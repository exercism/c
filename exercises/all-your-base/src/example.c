#include "all_your_base.h"
#include <math.h>

size_t rebase(int16_t digits[DIGITS_ARRAY_SIZE], int16_t fromBase,
              int16_t toBase, size_t numDigits)
{
   uint16_t denary = 0;
   size_t newNumDigits = 0;
   //bool leadingZeros = true;

   if ((fromBase <= 1) || (toBase <= 1) || (numDigits <= 0))
      return 0;                 /* invalid bases or length */
   if (digits[DIGITS_ARRAY_SIZE - numDigits] == 0)
      return 0;                 /* leading zeros */

   /* convert to denary */
   for (size_t i = DIGITS_ARRAY_SIZE - 1, j = 0;
        i >= DIGITS_ARRAY_SIZE - numDigits; --i, ++j) {
      if (digits[i] < 0)
         return 0;              /* negative digits */
      if (digits[i] >= fromBase)
         return 0;              /* invaid positive digit */
      denary += digits[i] * pow(fromBase, j);
   }

   /* calculate and store new digits */
   for (size_t i = DIGITS_ARRAY_SIZE - 1; denary > 0; --i) {
      digits[i] = denary % toBase;
      denary /= toBase;
      ++newNumDigits;
   }

   /* ensure rest of array is zero */
   for (int i = DIGITS_ARRAY_SIZE - (newNumDigits + 1); i >= 0; --i)
      digits[i] = 0;

   return newNumDigits;
}
