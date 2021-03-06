#include "linked_list.h"
#include <assert.h>
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

static struct list_node *list_node_create(struct list_node *prev,
                                          struct list_node *next,
                                          ll_data_t data)
{
   struct list_node *node = malloc(sizeof(*node));
   if (node) {
      node->prev = prev;
      node->next = next;
      node->data = data;
   }
   return node;
}

struct list *list_create(void)
{
   struct list *list = malloc(sizeof(*list));
   if (list) {
      list->first = NULL;
      list->last = NULL;
   }
   return list;
}

size_t list_count(const struct list * list)
{
   assert(list);

   size_t count = 0;
   struct list_node *node = list->first;

   while (node) {
      ++count;
      node = node->next;
   }

   return count;
}

void list_push(struct list *list, ll_data_t data)
{
   assert(list);
   struct list_node *node = list_node_create(list->last, NULL, data);
   if (!node)
      return;
   list->last = node;
   if (!list->first)
      list->first = node;
   else
      node->prev->next = node;
   return;
}

ll_data_t list_pop(struct list * list)
{
   assert(list);
   assert(list->last);
   struct list_node *node = list->last;
   ll_data_t result = node->data;
   list->last = node->prev;
   if (list->first == node)
      list->first = NULL;
   else
      node->prev->next = NULL;
   free(node);
   return result;
}

void list_unshift(struct list *list, ll_data_t data)
{
   assert(list);
   struct list_node *node = list_node_create(NULL, list->first, data);
   if (!node)
      return;
   list->first = node;
   if (!list->last)
      list->last = node;
   else
      node->next->prev = node;
   return;
}

ll_data_t list_shift(struct list * list)
{
   assert(list);
   assert(list->first);
   struct list_node *node = list->first;
   ll_data_t result = node->data;
   list->first = node->next;
   if (list->last == node)
      list->last = NULL;
   else
      node->next->prev = NULL;
   free(node);
   return result;
}

void list_delete(struct list *list, ll_data_t data)
{
   assert(list);

   struct list_node *node = list->first;

   while (node) {
      if (node->data == data) {
         if (node == list->first)
            list->first = node->next;
         else
            node->prev->next = node->next;

         if (node == list->last)
            list->last = node->prev;
         else
            node->next->prev = node->prev;

         free(node);
         return;
      }
      node = node->next;
   }
}

void list_destroy(struct list *list)
{
   if (!list)
      return;
   struct list_node *node = list->first;
   while (node) {
      struct list_node *next = node->next;
      free(node);
      node = next;
   }
   free(list);
}
