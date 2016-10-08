#include <string.h>
#include <stdbool.h>
#include "largest_series_product.h"

#define MAX(x, y) (x) > (y) ? (x) : (y)

static int to_int(char c)
{
   return c - '0';
}

static bool is_digit(char c)
{
   return (c >= '0') && (c <= '9');
}

int64_t largest_series_product(char *digits, size_t span)
{
   size_t digit_count = strlen(digits);
   size_t zeros = 0;
   long product = 1;
   long largest_product = 0;

   if (span > digit_count)
      return -1;

   if (!span && !digit_count)
      return 1;

   for (size_t i = 0; i < digit_count; i++) {
      if (!is_digit(digits[i]))
         return -1;

      int to_add = to_int(digits[i]);

      if (i >= span) {
         int to_remove = to_int(digits[i - span]);
         if (to_remove == 0)
            zeros--;
         else
            product /= to_remove;
      }

      if (to_add > 0)
         product *= to_add;
      else
         zeros++;

      if ((i + 1 >= span) && (zeros == 0))
         largest_product = MAX(largest_product, product);
   }

   return largest_product;
}
