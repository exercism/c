#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

struct list_item {
   struct list_item *next;
   struct list_item *prev;
   ll_data_t data;
};

struct list_item *head = NULL;

struct list_item *new(ll_data_t data)
{
   struct list_item *item = malloc(sizeof(*item));

   if (item != NULL) {
      item->next = NULL;
      item->prev = NULL;
      item->data = data;
   }
   return item;
}

ll_data_t item_data(struct list_item * item)
{
   ll_data_t result = 0;
   if (item != NULL) {
      result = item->data;
   }
   return result;
}

bool push(struct list_item * item)
{
   bool result = false;
   if (item != NULL) {
      if (head != NULL) {
         // climb list to tail
         struct list_item *old_tail = head;
         while (old_tail->next != NULL) {
            old_tail = old_tail->next;
         }
         // append new tail
         old_tail->next = item;
         item->prev = old_tail;
      } else {
         // add new tail as only item in list
         head = item;
      }
      result = true;
   }
   return result;
}

struct list_item *pop(void)
{
   struct list_item *old_tail = head;
   if (head != NULL) {
      // climb list to tail
      while (old_tail->next != NULL) {
         old_tail = old_tail->next;
      }

      if (old_tail != head) {
         // remove tail from preceding item
         old_tail->prev->next = NULL;
      } else {
         // remove only item from list
         head = NULL;
      }

      // prevent dangling pointers
      old_tail->next = NULL;
      old_tail->prev = NULL;
   }
   return old_tail;
}

struct list_item *shift(void)
{
   struct list_item *old_head = head;
   if (head != NULL) {
      // remove head from following item
      if (head->next != NULL) {
         head->next->prev = NULL;
      }
      // update list to start with following item
      head = head->next;

      // prevent dangling pointers
      old_head->next = NULL;
      old_head->prev = NULL;
   }
   return old_head;
}

bool unshift(struct list_item * item)
{
   bool result = false;
   if (item != NULL) {
      if (head != NULL) {
         // prepend new head
         head->prev = item;
         item->next = head;
         head = item;
      } else {
         // add new head as only item in list
         head = item;
      }
      result = true;
   }
   return result;
}

bool delete_item(struct list_item ** item)
{
   bool result = false;
   if (item != NULL) {
      free(*item);
      *item = NULL;
      result = true;
   }
   return result;
}

bool delete_list(void)
{
   bool result = true;
   struct list_item *item = NULL;

   // delete each item from the head until none
   // are left or an item deletion fails
   while (((item = shift()) != NULL) && result == true) {
      result = delete_item(&item);
   }
   return result;
}
