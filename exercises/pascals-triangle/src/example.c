#include "pascals_triangle.h"

size_t factorial(int n)
{
   if (n > 20 || n < 0) {
      return 0;
   } else {
      return (n == 0) ? 1 : n * factorial(n - 1);
   }
}

size_t combination(int n, int r)
{
   return (r > n || n > 20
           || n < 0) ? 0 : factorial(n) / (factorial(n - r) * factorial(r));
}

int pascals_triangle(int count, size_t input[][((count < 0) ? 1 : count)])
{
   if (count < 0) {
      input[0][0] = -1;
      return -1;
   }
   for (int n = 0; n < count; n++) {
      for (int rn = 0; rn < n; rn++) {
         input[n][rn] = combination(n, rn);
      }
   }
   return 0;
}
