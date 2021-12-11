#include "sum_of_multiples.h"
#include <stdbool.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
   unsigned int sum = 0;
   if (NULL == factors)
      return sum;

   for (unsigned int current = 1; current < limit; current++) {
      for (size_t i = 0; i < number_of_factors; i++) {
         if (0 != factors[i] && (current % factors[i]) == 0) {
            sum += current;
            break;
         }
      }
   }

   return sum;
}
