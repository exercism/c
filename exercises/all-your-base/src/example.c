#include "all_your_base.h"
#include <math.h>
#include <string.h>

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t fromBase,
              int16_t toBase, size_t numDigits)
{
   uint16_t denary = 0;
   size_t newNumDigits = 0;

   if ((fromBase <= 1) || (toBase <= 1) || (numDigits <= 0))
      return 0;                 /* invalid bases or length */
   if (digits[0] == 0)
      return 0;                 /* leading zeros */

   /* convert to denary */
   for (size_t i = 0; i < numDigits; ++i) {
      if (digits[i] < 0)
         return 0;              /* negative digits */
      if (digits[i] >= fromBase)
         return 0;              /* invaid positive digit */
      denary += digits[i] * pow(fromBase, (numDigits - i - 1));
   }

   /* calculate number of new digits */
   for (uint16_t j = denary; j > 0;) {
      j /= toBase;
      ++newNumDigits;
   }

   /* calculate and store new digits */
   for (size_t i = newNumDigits - 1; denary > 0; --i) {
      digits[i] = denary % toBase;
      denary /= toBase;
   }

   /* ensure rest of array is zero */
   memset(&digits[newNumDigits], 0, DIGITS_ARRAY_SIZE - newNumDigits);

   return newNumDigits;
}
