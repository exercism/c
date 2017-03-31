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
      int sum = aliquot_sum(n);
      if (sum > n) {
         class = abundant_number;
      } else if (sum < n) {
         class = deficient_number;
      } else {
         class = perfect_number;
      }
   }
   return class;
}
