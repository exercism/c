#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

unsigned int sieve(const unsigned int limit, primesArray_t primes)
{
   unsigned int numberOfPrimes = 0;
   unsigned char *numberIsPrime;

   // clear the results
   memset(primes, 0, sizeof(*primes));

   if (limit > 1) {
      //allocate 1 more than limit for convenience so the number and the index are same
      numberIsPrime = malloc(limit + 1);
      memset(numberIsPrime, 1, limit + 1);

      unsigned int maxFactor = sqrt(limit) + 1;

      // mark 0 and 1 as not prime
      for (unsigned int i = 0; i < 2; i++) {
         numberIsPrime[i] = 0;
      }

      // mark the remaining numbers in the array according to the algo.
      for (unsigned int index = 2; index < maxFactor;) {
         // mark all of multiples that can't be prime
         for (unsigned int nonPrimeIndex = (2 * index);
              nonPrimeIndex < (limit + 1); nonPrimeIndex += index) {
            numberIsPrime[nonPrimeIndex] = 0;
         }

         // adjust the index
         do {
            index++;
            if (numberIsPrime[index]) {
               break;
            }
         } while (index <= maxFactor);
      }
      // collect and count the primes found
      for (unsigned int i = 1; i < limit + 1; i++) {
         if (numberIsPrime[i]) {
            primes[numberOfPrimes++] = i;
         }
      }
      free(numberIsPrime);
   }
   return numberOfPrimes;
}
