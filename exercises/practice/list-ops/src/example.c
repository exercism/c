#include "list_ops.h"
#include <string.h>

list_t *new_list(size_t length, list_element_t elements[])
{
   list_t *list = malloc(sizeof(*list) + sizeof(list_element_t) * length);

   if (!list)
      return NULL;

   list->length = length;
   memcpy(list->elements, elements, sizeof(list_element_t) * length);

   return list;
}

list_t *append_list(list_t * list1, list_t * list2)
{
   if (!list1 || !list2)
      return NULL;

   size_t length = list1->length + list2->length;
   list_t *list = malloc(sizeof(*list) + sizeof(list_element_t) * (length));

   if (!list)
      return NULL;

   list->length = length;
   if (length) {
      memcpy(list->elements, list1->elements,
             sizeof(list_element_t) * list1->length);
      memcpy(&(list->elements[list1->length]), list2->elements,
             sizeof(list_element_t) * list2->length);
   }

   return list;
}

list_t *filter_list(list_t * list, bool(*filter) (list_element_t))
{
   if (!list || !filter)
      return NULL;

   list_t *filtered =
       malloc(sizeof(*list) + sizeof(list_element_t) * list->length);

   if (!filtered)
      return NULL;

   size_t j = 0;
   for (size_t i = 0; i < list->length && j < list->length; ++i) {
      if (filter(list->elements[i]))
         filtered->elements[j++] = list->elements[i];
   }
   filtered->length = j;

   return filtered;
}

size_t length_list(list_t * list)
{
   if (!list)
      return 0;
   return list->length;
}

list_t *map_list(list_t * list, list_element_t(*map) (list_element_t))
{
   if (!list || !map)
      return NULL;

   list_t *mapped =
       malloc(sizeof(*list) + sizeof(list_element_t) * list->length);

   if (!mapped)
      return NULL;

   mapped->length = list->length;
   for (size_t i = 0; i < mapped->length; ++i)
      mapped->elements[i] = map(list->elements[i]);

   return mapped;
}

list_element_t foldl_list(list_t * list, list_element_t initial,
                          list_element_t(*foldl) (list_element_t,
                                                  list_element_t))
{
   if (!list || !foldl)
      return 0;

   for (size_t i = 0; i < list->length; ++i)
      initial = foldl(list->elements[i], initial);

   return initial;
}

list_element_t foldr_list(list_t * list, list_element_t initial,
                          list_element_t(*foldr) (list_element_t,
                                                  list_element_t))
{
   if (!list || !foldr)
      return 0;

   for (size_t i = list->length; i > 0; --i)
      initial = foldr(list->elements[i - 1], initial);

   return initial;
}

list_t *reverse_list(list_t * list)
{
   if (!list)
      return NULL;

   list_t *reversed =
       malloc(sizeof(*list) + sizeof(list_element_t) * list->length);

   if (!reversed)
      return NULL;

   reversed->length = list->length;
   for (size_t i = 0, j = reversed->length - 1; i < reversed->length; i++, j--) {
      reversed->elements[i] = list->elements[j];
   }

   return reversed;
}

void delete_list(list_t * list)
{
   free(list);
}
