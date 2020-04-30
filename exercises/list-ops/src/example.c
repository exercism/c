#include "list_ops.h"
#include <string.h>

list_t *new_list(size_t length, list_value_t values[])
{
   list_t *list = malloc(sizeof(*list) + sizeof(list_value_t) * length);

   if (!list)
      return NULL;

   list->length = length;
   memcpy(list->values, values, sizeof(list_value_t) * length);

   return list;
}

list_t *append_list(list_t * list1, list_t * list2)
{
   if (!list1 || !list2)
      return NULL;

   size_t length = list1->length + list2->length;
   list_t *list = malloc(sizeof(*list) + sizeof(list_value_t) * (length));

   if (!list)
      return NULL;

   list->length = length;
   if (length) {
      memcpy(list->values, list1->values, sizeof(list_value_t) * list1->length);
      memcpy(&(list->values[list1->length]), list2->values,
             sizeof(list_value_t) * list2->length);
   }

   return list;
}

list_t *filter_list(list_t * list, bool (*filter)(list_value_t value))
{
   if(!list || !filter)
      return NULL;

   list_t *filtered =
       malloc(sizeof(*list) + sizeof(list_value_t) * list->length);

   if (!filtered)
      return NULL;

   size_t j = 0;
   for (size_t i = 0; i < list->length && j < list->length; ++i) {
      if (filter(list->values[i]))
         filtered->values[j++] = list->values[i];
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

list_t *map_list(list_t * list, list_value_t(*map) (list_value_t value))
{
   if (!list || !map)
      return NULL;

   list_t *mapped = malloc(sizeof(*list) + sizeof(list_value_t) * list->length);

   if (!mapped)
      return NULL;

   mapped->length = list->length;
   for (size_t i = 0; i < mapped->length; ++i)
      mapped->values[i] = map(list->values[i]);

   return mapped;
}

list_value_t foldl_list(list_t * list, list_value_t initial,
                        list_value_t(*foldl) (list_value_t value,
                                              list_value_t initial))
{
   if (!list || !foldl)
      return 0;

   for (size_t i = 0; i < list->length; ++i)
      initial = foldl(list->values[i], initial);

   return initial;
}

list_value_t foldr_list(list_t * list, list_value_t initial,
                        list_value_t(*foldr) (list_value_t value,
                                              list_value_t initial))
{
   if (!list || !foldr)
      return 0;

   for (size_t i = list->length; i > 0; --i)
      initial = foldr(list->values[i - 1], initial);

   return initial;
}

list_t *reverse_list(list_t * list)
{
   if (!list)
      return NULL;

   list_t *reversed =
       malloc(sizeof(*list) + sizeof(list_value_t) * list->length);

   if (!reversed)
      return NULL;

   reversed->length = list->length;
   for (size_t i = 0, j = reversed->length - 1; i < reversed->length; i++, j--) {
      reversed->values[i] = list->values[j];
   }

   return reversed;
}

void delete_list(list_t * list)
{
   free(list);
}
