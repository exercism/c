#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

struct list_item {
   struct list_item *next;
   struct list_item *prev;
   ll_data_t data;
};

static struct list_item *new_item(ll_data_t data)
{
   struct list_item *item = malloc(sizeof(*item));

   if (item != NULL) {
      item->next = NULL;
      item->prev = NULL;
      item->data = data;
   }
   return item;
}

static struct list_item *get_list_tail(struct list_item **list)
{
   struct list_item *tail = NULL;
   if (list != NULL) {
      // climb list to tail
      tail = *list;
      while (tail->next != NULL) {
         tail = tail->next;
      }
   }
   return tail;
}

static void delete_item(struct list_item *item)
{
   if (item != NULL) {
      free(item);
   }
}

struct list_item **new_list(void)
{
   struct list_item **list = malloc(sizeof(struct list_item *));
   if (list != NULL) {
      *list = NULL;
   }
   return list;
}

bool is_list_empty(struct list_item ** list)
{
   return (list == NULL || *list == NULL);
}

bool push(struct list_item ** list, ll_data_t item_data)
{
   bool result = false;
   if (list != NULL) {
      struct list_item *item = new_item(item_data);
      if (item != NULL) {
         if (*list != NULL) {
            struct list_item *old_tail = get_list_tail(list);
            // append new tail
            old_tail->next = item;
            item->prev = old_tail;
         } else {
            // add new tail as only item in list
            *list = item;
         }
         result = true;
      }
   }
   return result;
}

ll_data_t pop(struct list_item ** list)
{
   // result is undefined because type may change
   ll_data_t result;
   if (list != NULL && *list != NULL) {
      struct list_item *old_tail = get_list_tail(list);

      if (old_tail != *list) {
         // remove tail from preceding item
         old_tail->prev->next = NULL;
      } else {
         // remove only item from list
         *list = NULL;
      }

      result = old_tail->data;
      delete_item(old_tail);
   }
   return result;
}

ll_data_t shift(struct list_item ** list)
{
   // result is undefined because type may change
   ll_data_t result;
   if (list != NULL && *list != NULL) {
      struct list_item *old_head = *list;

      // remove head from following item
      if ((*list)->next != NULL) {
         (*list)->next->prev = NULL;
      }
      // update list to start with following item
      *list = (*list)->next;

      result = old_head->data;
      delete_item(old_head);
   }
   return result;
}

bool unshift(struct list_item ** list, ll_data_t item_data)
{
   bool result = false;
   if (list != NULL) {
      struct list_item *item = new_item(item_data);
      if (item != NULL) {
         if (*list != NULL) {
            // prepend new head
            (*list)->prev = item;
            item->next = *list;
            *list = item;
         } else {
            // add new head as only item in list
            *list = item;
         }
      }
      result = true;
   }
   return result;
}

void delete_list(struct list_item **list)
{
   // shift off each item until list is empty
   while (!is_list_empty(list)) {
      shift(list);
   }
   // free the head
   if (list != NULL) {
      free(list);
   }
}
