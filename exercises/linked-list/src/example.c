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

bool list_is_empty(const struct list *list)
{
   assert(list);
   return list->first == NULL;
}

bool list_push(struct list *list, ll_data_t data)
{
   assert(list);
   struct list_node *node = list_node_create(list->last, NULL, data);
   if (!node)
      return NULL;
   list->last = node;
   if (!list->first)
      list->first = node;
   else
      node->prev->next = node;
   return node;
}

ll_data_t list_pop(struct list *list)
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

bool list_unshift(struct list *list, ll_data_t data)
{
   assert(list);
   struct list_node *node = list_node_create(NULL, list->first, data);
   if (!node)
      return NULL;
   list->first = node;
   if (!list->last)
      list->last = node;
   else
      node->next->prev = node;
   return node;
}

ll_data_t list_shift(struct list *list)
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
