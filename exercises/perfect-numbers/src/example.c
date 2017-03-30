#include "perfect_numbers.h"

static int aliquot_sum(int n)
{
   int result = 0;
   for (int i = 1; i < n; ++i) {
      if ((n % i) == 0) {
         result = result + i;
      }
   }
   return result;
}

kind classify_number(int n)
{
   if (n <= 0) {
      return error;
   }
   int buf = aliquot_sum(n);
   if (buf == n) {
      return perfect_number;
   } else if (buf > n) {
      return abundant_number;
   } else if (buf < n) {
      return deficient_number;
   }
   return error;
}
