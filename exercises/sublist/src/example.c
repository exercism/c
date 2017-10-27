#include "sublist.h"
#include <stdbool.h>
#include <string.h>

static bool is_equal(int *list_one, int *list_two,
                     size_t list_one_element_count,
                     size_t list_two_element_count)
{
   return (list_one_element_count == list_two_element_count
           && !memcmp(list_one, list_two,
                      list_one_element_count * sizeof(int)));
}

static bool is_sublist(int *list_one, int *list_two,
                       size_t list_one_element_count,
                       size_t list_two_element_count)
{
   int i;
   int loop_end = (list_two_element_count - list_one_element_count);

   if (list_one_element_count > list_two_element_count) {
      return false;
   }

   for (i = 0; i <= loop_end; i++) {
      if (!memcmp(list_one, &list_two[i], list_one_element_count * sizeof(int))) {
         return true;
      }
   }

   return false;
}

static bool is_superlist(int *list_one, int *list_two,
                         size_t list_one_element_count,
                         size_t list_two_element_count)
{
   return is_sublist(list_two, list_one, list_two_element_count,
                     list_one_element_count);
}

comparison_result_t check_lists(int *list_one, int *list_two,
                                size_t list_one_element_count,
                                size_t list_two_element_count)
{
   if (is_equal
       (list_one, list_two, list_one_element_count, list_two_element_count)) {
      return EQUAL;
   } else
       if (is_sublist
           (list_one, list_two, list_one_element_count,
            list_two_element_count)) {
      return SUBLIST;
   } else
       if (is_superlist
           (list_one, list_two, list_one_element_count,
            list_two_element_count)) {
      return SUPERLIST;
   }

   return UNEQUAL;
}
