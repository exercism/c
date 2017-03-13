#include <stdlib.h>
#include "react.h"

enum cell_kind {
   kind_input,
   kind_compute1,
   kind_compute2,
};

struct child {
   struct cell *cell;
   struct child *next;
};

struct cb {
   callback_id id;
   callback f;
   void *obj;
   struct cb *next;
};

struct reactor {
   struct child *first;
   struct child *last;
};

struct cell {
   struct reactor *reactor;
   int value;
   enum cell_kind kind;
   struct cell *input1;
   struct cell *input2;
   compute1 compute1;
   compute2 compute2;
   struct cb *cb;
   int callbacks_issued;
};

struct reactor *create_reactor()
{
   struct reactor *r = calloc(1, sizeof(struct reactor));
   return r;
}

void destroy_reactor(struct reactor *r)
{
   struct child *child = r->first;
   while (child) {
      struct cb *cb = child->cell->cb;
      while (cb) {
         struct cb *next_cb = cb->next;
         free(cb);
         cb = next_cb;
      }
      free(child->cell);

      struct child *next = child->next;
      free(child);
      child = next;
   }
   free(r);
}

#define SUCCESS 1
#define FAIL 0

static int add_child(struct reactor *r, struct cell *cell)
{
   struct child *child = calloc(1, sizeof(struct child));
   if (!child) {
      return FAIL;
   }
   child->cell = cell;
   if (!r->first) {
      r->first = child;
   } else {
      r->last->next = child;
   }
   r->last = child;
   return SUCCESS;
}

struct cell *create_input_cell(struct reactor *r, int initial_value)
{
   struct cell *c = calloc(1, sizeof(struct cell));
   if (!c) {
      return NULL;
   }
   if (add_child(r, c) != SUCCESS) {
      free(c);
      return NULL;
   }
   c->reactor = r;
   c->kind = kind_input;
   c->value = initial_value;
   return c;
}

struct cell *create_compute1_cell(struct reactor *r, struct cell *input,
                                  compute1 compute)
{
   struct cell *c = calloc(1, sizeof(struct cell));
   if (!c) {
      return NULL;
   }
   if (add_child(r, c) != SUCCESS) {
      free(c);
      return NULL;
   }
   c->reactor = r;
   c->kind = kind_compute1;
   c->input1 = input;
   c->compute1 = compute;
   c->value = compute(cell_value(input));
   return c;
}

struct cell *create_compute2_cell(struct reactor *r, struct cell *input1,
                                  struct cell *input2, compute2 compute)
{
   struct cell *c = calloc(1, sizeof(struct cell));
   if (!c) {
      return NULL;
   }
   if (add_child(r, c) != SUCCESS) {
      free(c);
      return NULL;
   }
   c->reactor = r;
   c->kind = kind_compute2;
   c->input1 = input1;
   c->input2 = input2;
   c->compute2 = compute;
   c->value = compute(cell_value(input1), cell_value(input2));
   return c;
}

int cell_value(struct cell *c)
{
   return c->value;
}

static void propagate(struct cell *c)
{
   int new_value;
   switch (c->kind) {
   case kind_compute1:
      new_value = c->compute1(cell_value(c->input1));
      break;
   case kind_compute2:
      new_value = c->compute2(cell_value(c->input1), cell_value(c->input2));
      break;
   default:
      return;
   }

   if (new_value != c->value) {
      c->value = new_value;
      for (struct cb * cb = c->cb; cb; cb = cb->next) {
         cb->f(cb->obj, new_value);
      }
   }

}

void cell_value_set(struct cell *c, int new_value)
{
   c->value = new_value;
   struct reactor *r = c->reactor;

   // We take the very naive route of updating all cells.
   // Traversing the tree and only updating the cells dependent on the just-changed cell is possible,
   // but requires much more memory management to make each cell aware of its dependents.
   for (struct child * child = r->first; child; child = child->next) {
      propagate(child->cell);
   }
}

callback_id add_callback(struct cell *c, void *obj, callback f)
{
   struct cb *cb = calloc(1, sizeof(struct cb));
   if (!cb) {
      return -1;
   }
   cb->id = c->callbacks_issued++;
   cb->next = c->cb;
   cb->obj = obj;
   cb->f = f;
   c->cb = cb;
   return cb->id;
}

void remove_callback(struct cell *c, callback_id to_remove)
{
   if (!c->cb) {
      return;
   } else if (c->cb->id == to_remove) {
      struct cb *to_free = c->cb;
      c->cb = c->cb->next;
      free(to_free);
      return;
   }
   for (struct cb * prev = c->cb, *cb = c->cb->next; cb;
        prev = prev->next, cb = cb->next) {
      if (cb->id == to_remove) {
         prev->next = cb->next;
         free(cb);
         return;
      }
   }
}
