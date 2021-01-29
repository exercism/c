#include <stdlib.h>
#include "react.h"

enum cell_kind {
   KIND_INPUT,
   KIND_COMPUTE_1,
   KIND_COMPUTE_2,
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
   struct child *input;
};

struct cell {
   int value;
   enum cell_kind kind;
   struct child *child;

   struct cell *input1;
   struct cell *input2;
   compute1 compute1;
   compute2 compute2;

   int last_cb_value;
   struct cb *cb;
   int callbacks_issued;
};

struct reactor *create_reactor()
{
   return calloc(1, sizeof(struct reactor));
}

static void destroy_cell(struct cell *c)
{
   struct cb *cb = c->cb;
   while (cb) {
      struct cb *next_cb = cb->next;
      free(cb);
      cb = next_cb;
   }

   struct child *child = c->child;
   while (child) {
      struct child *next = child->next;
      if (c == child->cell->input1) {
         // Don't double-free for a compute2 cell.
         destroy_cell(child->cell);
      }
      free(child);
      child = next;
   }

   free(c);
}

void destroy_reactor(struct reactor *r)
{
   struct child *input = r->input;
   while (input) {
      struct child *next = input->next;
      destroy_cell(input->cell);
      free(input);
      input = next;
   }

   free(r);
}

#define SUCCESS 1
#define FAIL 0

static int add_child(struct child **list, struct cell *cell)
{
   struct child *child = calloc(1, sizeof(struct child));
   if (!child) {
      return FAIL;
   }
   child->cell = cell;
   child->next = *list;
   *list = child;
   return SUCCESS;
}

static void remove_child(struct child **list)
{
   struct child *to_remove = *list;
   *list = to_remove->next;
   free(to_remove);
}

struct cell *create_input_cell(struct reactor *r, int initial_value)
{
   struct cell *c = calloc(1, sizeof(struct cell));
   if (!c) {
      return NULL;
   }
   if (add_child(&r->input, c) != SUCCESS) {
      free(c);
      return NULL;
   }
   c->kind = KIND_INPUT;
   c->value = initial_value;
   return c;
}

struct cell *create_compute1_cell(struct reactor *r, struct cell *input,
                                  compute1 compute)
{
   (void)r;
   struct cell *c = calloc(1, sizeof(struct cell));
   if (!c) {
      return NULL;
   }
   if (add_child(&input->child, c) != SUCCESS) {
      free(c);
      return NULL;
   }
   c->kind = KIND_COMPUTE_1;
   c->input1 = input;
   c->compute1 = compute;
   c->value = compute(get_cell_value(input));
   c->last_cb_value = c->value;
   return c;
}

struct cell *create_compute2_cell(struct reactor *r, struct cell *input1,
                                  struct cell *input2, compute2 compute)
{
   (void)r;
   struct cell *c = calloc(1, sizeof(struct cell));
   if (!c) {
      return NULL;
   }
   if (add_child(&input1->child, c) != SUCCESS) {
      free(c);
      return NULL;
   }
   if (add_child(&input2->child, c) != SUCCESS) {
      remove_child(&input1->child);
      free(c);
      return NULL;
   }
   c->kind = KIND_COMPUTE_2;
   c->input1 = input1;
   c->input2 = input2;
   c->compute2 = compute;
   c->value = compute(get_cell_value(input1), get_cell_value(input2));
   c->last_cb_value = c->value;
   return c;
}

#define each_child(c) struct child *child = (c)->child; child; child = child->next

int get_cell_value(struct cell *c)
{
   return c->value;
}

static void propagate(struct cell *c)
{
   int new_value;
   switch (c->kind) {
   case KIND_COMPUTE_1:
      new_value = c->compute1(get_cell_value(c->input1));
      break;
   case KIND_COMPUTE_2:
      new_value =
          c->compute2(get_cell_value(c->input1), get_cell_value(c->input2));
      break;
   default:
      return;
   }

   if (new_value != c->value) {
      c->value = new_value;
      for (each_child(c)) {
         propagate(child->cell);
      }
   }
}

static void fire_callbacks(struct cell *c)
{
   if (c->value == c->last_cb_value) {
      return;
   }
   c->last_cb_value = c->value;
   for (struct cb * cb = c->cb; cb; cb = cb->next) {
      cb->f(cb->obj, c->value);
   }
   for (each_child(c)) {
      fire_callbacks(child->cell);
   }
}

void set_cell_value(struct cell *c, int new_value)
{
   c->value = new_value;
   for (each_child(c)) {
      propagate(child->cell);
   }
   for (each_child(c)) {
      // Why can't we put propagate and fire_callbacks in same for loop?
      // Because then a compute2 cell might fire its callbacks too early
      // (before it's seen updates from both of its inputs)!
      fire_callbacks(child->cell);
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
   }
   // this dummy starting node reduces code duplication,
   // in case the ID to remove is at the head of the list.
   struct cb dummy;
   dummy.next = c->cb;
   for (struct cb * prev = &dummy, *cb = c->cb; cb;
        prev = prev->next, cb = cb->next) {
      if (cb->id == to_remove) {
         if (cb == c->cb) {
            c->cb = cb->next;
         }
         prev->next = cb->next;
         free(cb);
         return;
      }
   }
}
