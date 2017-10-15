#include "sum_of_multiples.h"
#include <stdbool.h>

unsigned int sum_of_multiples(const unsigned int *multiples,
                              const size_t number_of_multiples,
                              const unsigned int upper_bound)
{
   unsigned int sum = 0;
   if (NULL == multiples)
      return sum;

   for (unsigned int current = 1; current < upper_bound; current++) {
      for (size_t i = 0; i < number_of_multiples; i++) {
         if (0 != multiples[i] && (current % multiples[i]) == 0) {
            sum += current;
            break;
         }
      }
   }

   return sum;
}
