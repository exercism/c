#include "perfect_numbers.h"

static int aliquot_sum(int n)
{
   if (n == 1) {
      return 0;
   }
   int result = 1;
   int i;
   for (i = 2; i * i < n; ++i) {
      if ((n % i) == 0) {
         result += i + (n / i);
      }
   }
   return result + (i * i == n ? i : 0);
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
