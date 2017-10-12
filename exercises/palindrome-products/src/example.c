#include "palindrome_products.h"
#include <stdbool.h>

/* Return true if the product of a and b is a palindrome, false otherwise */
bool is_palindrome_product(int a, int b)
{
   int ret = 0, prod = a * b;
   while (prod) {
      ret *= 10;
      ret += prod % 10;
      prod /= 10;
   }
   return (a * b) == ret;
}

product_t get_palindrome_product(int min, int max)
{
   product_t ret;
   ret.smallest = 0;
   ret.largest = 0;
   bool largest = false;

   for (int i = min; i <= max; i++) {
      for (int j = min; j <= max; j++) {
         if (is_palindrome_product(i, j) == true) {
            if (largest == false) {
               ret.smallest = i * j;
               largest = true;
            } else {
               ret.largest = i * j;
            }
         }
      }
   }
   return ret;
}
