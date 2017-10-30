#include "sublist.h"
#include <stdbool.h>
#include <string.h>

static bool is_equal(int *list_to_compare, int *base_list,
                     size_t list_to_compare_element_count,
                     size_t base_list_element_count)
{
   return (list_to_compare_element_count == base_list_element_count
           && !memcmp(list_to_compare, base_list,
                      list_to_compare_element_count * sizeof(int)));
}

static bool is_sublist(int *list_to_compare, int *base_list,
                       size_t list_to_compare_element_count,
                       size_t base_list_element_count)
{
   int i;
   int loop_end = (base_list_element_count - list_to_compare_element_count);

   if (list_to_compare_element_count > base_list_element_count) {
      return false;
   }

   for (i = 0; i <= loop_end; i++) {
      if (!memcmp
          (list_to_compare, &base_list[i],
           list_to_compare_element_count * sizeof(int))) {
         return true;
      }
   }

   return false;
}

static bool is_superlist(int *list_to_compare, int *base_list,
                         size_t list_to_compare_element_count,
                         size_t base_list_element_count)
{
   return is_sublist(base_list, list_to_compare, base_list_element_count,
                     list_to_compare_element_count);
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
   if (is_equal
       (list_to_compare, base_list, list_to_compare_element_count,
        base_list_element_count)) {
      return EQUAL;
   } else if (is_sublist
              (list_to_compare, base_list, list_to_compare_element_count,
               base_list_element_count)) {
      return SUBLIST;
   } else if (is_superlist
              (list_to_compare, base_list, list_to_compare_element_count,
               base_list_element_count)) {
      return SUPERLIST;
   }

   return UNEQUAL;
}
