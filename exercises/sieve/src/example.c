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

      // mark 0 and 1 as not prime
      for (unsigned int i = 0; i < 2; i++) {
         numberIsPrime[i] = 0;
      }

      // mark the remaining numbers in the array according to the algo.
      for (unsigned int i = 2; i < sqrt(limit) + 1; i++) {
         // mark all of multiples that can't be prime
         for (unsigned int nonPrimeIndex = (2 * i); nonPrimeIndex < (limit + 1);
              nonPrimeIndex += i) {
            numberIsPrime[nonPrimeIndex] = 0;
         }

         // adjust the index i - normally bad practice within a loop but ok here as always making equivalent or larger
         for (unsigned int newStartIndex = i + 1;
              newStartIndex < sqrt(limit) + 1; newStartIndex++) {
            if (numberIsPrime[newStartIndex]) {
               i = newStartIndex - 1;   // need to account for the ++ of the outer for loop
               break;
            }
         }
      }
      // collect and count the primes found
      for (unsigned int i = 1; i < limit + 1; i++) {
         if (numberIsPrime[i]) {
            primes[numberOfPrimes++] = i;
         }
      }
   }
   return numberOfPrimes;
}
