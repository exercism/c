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
   kind class = error;
   if (n > 0) {
      int buf = aliquot_sum(n);
      if (buf > n) {
         class = abundant_number;
      } else if (buf < n) {
         class = deficient_number;
      } else {
         class = perfect_number;
      }
   }
   return class;
}
