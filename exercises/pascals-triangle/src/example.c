#include "pascals_triangle.h"

long long unsigned int factorial(int n)
{
   return (n == 0) ? 1 : n * factorial(n - 1);
}

long long unsigned int combination(int n, int r)
{
   return (r > n) ? 0 : factorial(n) / (factorial(n - r) * factorial(r));
}

int pascals_triangle(int count, int input[][((count < 0) ? 1 : count)])
{
   if (count < 0) {
      memset(input, -1, sizeof(int) * count * count);
      return -1;
   }
   memset(input, 0, sizeof(int) * count * count);
   for (int n = 0; n < count; n++) {
      for (int rn = 0; rn < n; rn++) {
         input[n][rn] = combination(n, rn);
      }
   }
   return 0;
}
