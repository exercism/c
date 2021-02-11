#include "nth_prime.h"
#include <stdbool.h>

static bool is_prime(uint32_t n)
{
   for (uint32_t i = 2; (i * i) < (n + 1); ++i) {
      if (n % i == 0) {
         return false;
      }
   }

   return true;
}

uint32_t nth(uint32_t n)
{
   uint32_t candidate = 1;
   uint32_t count = 0;

   if (n < 1) {
      return 0;
   }

   while (count < n) {
      if (is_prime(++candidate)) {
         count++;
      }
   }

   return candidate;
}
