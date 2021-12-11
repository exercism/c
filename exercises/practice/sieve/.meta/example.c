#include "sieve.h"

#include <stdbool.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
   if (limit <= 1) {
      // no primes that small
      return 0;
   }
   // allocate one boolean for each number in [0,limit]
   bool *is_marked = calloc(limit + 1, sizeof(*is_marked));
   if (!is_marked) {
      return 0;
   }

   uint32_t n_primes = 0;

   for (uint32_t i = 2; i <= limit; i++) {
      if (is_marked[i]) {
         // current number `i` is already marked
         continue;
      }
      // `i` is the smallest number that is not marked and therefore prime
      primes[n_primes++] = i;

      if (n_primes == max_primes) {
         // we reached the maximum number of primes
         break;
      }
      // mark the multiples of `i` in [i*2, limit]
      for (uint32_t p = 2 * i; p <= limit; p += i) {
         is_marked[p] = true;
      }
   }

   free(is_marked);

   return n_primes;
}
