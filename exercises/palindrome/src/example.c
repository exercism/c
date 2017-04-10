#include "palindrome.h"
#include <stdbool.h>

/* Return true if the product of a and b is a palindrome, false otherwise */
bool isPalindromeProduct(int a, int b)
{
   int ret = 0, prod = a * b;
   while (prod) {
      ret *= 10;
      ret += prod % 10;
      prod /= 10;
   }
   return (a * b) == ret;
}

Pair getPalindromeProduct(int min, int max)
{
   Pair ret = { 0 };
   bool largest = false;

   for (int i = min; i <= max; i++) {
      for (int j = min; j <= max; j++) {
         if (isPalindromeProduct(i, j) == true) {
            if (largest == false) {
               ret.small_palind = i * j;
               largest = true;
            } else {
               ret.larg_palind = i * j;
            }
         }
      }
   }
   return ret;
}
