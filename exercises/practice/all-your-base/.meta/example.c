#include "all_your_base.h"
#include <math.h>
#include <string.h>

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t from_base,
              int16_t to_base, size_t num_digits)
{
   uint16_t denary = 0;
   size_t new_num_digits = 0;

   if ((digits == NULL) || (num_digits == 0))
      return 0;                 /* invalid list or length */
   if ((from_base <= 1) || (to_base <= 1))
      return 0;                 /* invalid bases */

   size_t first_non_zero = 0;
   for (size_t i = 0; i < num_digits && digits[i] == 0; ++i)
      ++first_non_zero;         /* skip leading zeros */

   /* convert to denary */
   for (size_t i = first_non_zero; i < num_digits; ++i) {
      if (digits[i] < 0)
         return 0;              /* negative digits */
      if (digits[i] >= from_base)
         return 0;              /* invaid positive digit */
      denary += digits[i] * pow(from_base, (num_digits - i - 1));
   }

   /* calculate number of new digits */
   uint16_t j = denary;
   do {
      ++new_num_digits;
    } while ((j /= to_base) != 0);

   /* calculate and store new digits */
   digits[0] = 0;
   for (size_t i = new_num_digits - 1; denary > 0; --i) {
      digits[i] = denary % to_base;
      denary /= to_base;
   }

   /* ensure rest of array is zero */
   memset(&digits[new_num_digits], 0, DIGITS_ARRAY_SIZE - new_num_digits);

   return new_num_digits;
}
