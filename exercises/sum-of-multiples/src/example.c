#include "sum_of_multiples.h"
#include <stdbool.h>

unsigned int sum_of_multiples_to(const unsigned int *multiples, const size_t number_of_multiples, const int upper_bound)
{
   unsigned int sum = 0;

   for (int current = 1; current < upper_bound; current++) {
      bool is_multiple = false;

      for (size_t i = 0; i < number_of_multiples; i++) {
         if ((current % multiples[i]) == 0) {
            is_multiple = true;
            break;
         }
      }

      if (is_multiple) {
         sum += current;
      }
   }

   return sum;
}
