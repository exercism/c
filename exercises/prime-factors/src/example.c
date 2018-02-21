#include "prime_factors.h"
#include <math.h>

/**
 * find prime factors: brute force version
 * https://en.wikipedia.org/wiki/Trial_division
 */
size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
   int count = 0;
   while ((n % 2 == 0) && (count < MAXFACTORS)) {
      factors[count++] = 2;
      n /= 2;
   }

   for (uint64_t i = 3; (i <= sqrt(n)) && (count < MAXFACTORS); i += 2) {
      while (n % i == 0) {
         factors[count++] = i;
         n /= i;
      }
   }

   if (n > 2) {
      factors[count++] = n;
   }

   return count;
}
