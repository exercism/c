#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

unsigned int sieve(const unsigned int limit, primes_array_t primes)
{
   unsigned int number_of_primes = 0;

   // clear the results
   memset(primes, 0, sizeof(*primes));

   if (limit > 1) {
      //allocate 1 more than limit for convenience so the number and the index are same
      unsigned char *number_is_prime = malloc(limit + 1);
      memset(number_is_prime, 1, limit + 1);

      unsigned int max_factor = sqrt(limit) + 1;

      // mark 0 and 1 as not prime
      for (unsigned int i = 0; i < 2; i++) {
         number_is_prime[i] = 0;
      }

      // mark the remaining numbers in the array according to the algo.
      for (unsigned int index = 2; index < max_factor;) {
         // mark all of multiples that can't be prime
         for (unsigned int non_prime_index = (2 * index);
              non_prime_index < (limit + 1); non_prime_index += index) {
            number_is_prime[non_prime_index] = 0;
         }

         // adjust the index
         do {
            index++;
            if (number_is_prime[index]) {
               break;
            }
         } while (index <= max_factor);
      }
      // collect and count the primes found
      for (unsigned int i = 1; i < limit + 1; i++) {
         if (number_is_prime[i]) {
            primes[number_of_primes++] = i;
         }
      }
      free(number_is_prime);
   }
   return number_of_primes;
}
