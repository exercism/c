#include "list_ops.h"

static list_item_t *new_item(list_data_t data)
{
   list_item_t *item = malloc(sizeof(*item));

   if (item != NULL) {
      item->next = NULL;
      item->prev = NULL;
      item->data = data;
   }
   return item;
}

static list_item_t *get_list_tail(list_item_t ** list)
{
   list_item_t *tail = NULL;
   if (list != NULL) {
      // climb list to tail
      tail = *list;
      while (tail->next != NULL) {
         tail = tail->next;
      }
   }
   return tail;
}

static void delete_item(list_item_t * item)
{
   if (item != NULL) {
      free(item);
   }
}

static list_item_t *peek_first(list_item_t ** list)
{
   list_item_t *first = NULL;
   if (!is_list_empty(list))
      first = *list;
   return first;
}

static list_item_t *peek_last(list_item_t ** list)
{
   return get_list_tail(list);
}

static list_item_t *peek_next(list_item_t * item)
{
   list_item_t *next = NULL;
   if (item != NULL)
      next = item->next;
   return next;
}

static list_item_t *peek_previous(list_item_t * item)
{
   list_item_t *prev = NULL;
   if (item != NULL)
      prev = item->prev;
   return prev;
}

list_item_t **new_list(void)
{
   list_item_t **list = malloc(sizeof(list_item_t *));
   if (list != NULL) {
      *list = NULL;
   }
   return list;
}

bool is_list_empty(list_item_t ** list)
{
   return (list == NULL || *list == NULL);
}

bool push(list_item_t ** list, list_data_t item_data)
{
   bool result = false;
   if (list != NULL) {
      list_item_t *item = new_item(item_data);
      if (item != NULL) {
         if (*list != NULL) {
            list_item_t *old_tail = get_list_tail(list);
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

list_data_t shift(list_item_t ** list)
{
   list_data_t result = 0;
   if (list != NULL && *list != NULL) {
      list_item_t *old_head = *list;

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

void delete_list(list_item_t ** list)
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

bool append_list(list_item_t ** list1, list_item_t ** list2)
{
   bool result = false;
   if (list1 != NULL && list2 != NULL) {
      list_item_t *next_item = peek_first(list2);
      while (next_item) {
         if (!(result = push(list1, next_item->data)))
            break;
         next_item = peek_next(next_item);
      }
      result = true;
   }
   return result;
}

list_item_t **filter_list(list_item_t ** list,
                          list_item_t * (*filter) (list_item_t *))
{
   list_item_t **filtered = new_list();

   if (!is_list_empty(list)) {
      list_item_t *next_item = peek_first(list);
      while (next_item) {
         list_item_t *f = NULL;
         if ((f = filter(next_item))) {
            if (!(push(filtered, f->data)))
               break;
         }
         next_item = peek_next(next_item);
      }
   }

   return filtered;
}

size_t length_list(list_item_t ** list)
{
   size_t length = 0;

   if (!is_list_empty(list)) {
      list_item_t *next_item = peek_first(list);
      while (next_item) {
         ++length;
         next_item = peek_next(next_item);
      }
   }

   return length;
}

list_item_t **map_list(list_item_t ** list, list_data_t(*map) (list_data_t))
{
   list_item_t **mapped = new_list();

   if (!is_list_empty(list)) {
      list_item_t *next_item = peek_first(list);
      while (next_item) {
         list_data_t data = map(next_item->data);
         if (!(push(mapped, data)))
            break;
         next_item = peek_next(next_item);
      }
   }

   return mapped;
}

list_data_t foldl_list(list_item_t ** list, list_data_t initial,
                       list_data_t(*foldl) (list_data_t, list_data_t))
{
   if (!is_list_empty(list)) {
      list_item_t *next_item = peek_first(list);
      while (next_item) {
         initial = foldl(next_item->data, initial);
         next_item = peek_next(next_item);
      }
   }

   return initial;
}

list_data_t foldr_list(list_item_t ** list, list_data_t initial,
                       list_data_t(*foldr) (list_data_t, list_data_t))
{
   if (!is_list_empty(list)) {
      list_item_t *prev_item = peek_last(list);
      while (prev_item) {
         initial = foldr(prev_item->data, initial);
         prev_item = peek_previous(prev_item);
      }
   }

   return initial;
}

list_item_t **reverse_list(list_item_t ** list)
{
   list_item_t **reversed = new_list();

   if (!is_list_empty(list)) {
      list_item_t *prev_item = peek_last(list);
      while (prev_item) {
         if (!(push(reversed, prev_item->data)))
            break;
         prev_item = peek_previous(prev_item);
      }
   }

   return reversed;
}
