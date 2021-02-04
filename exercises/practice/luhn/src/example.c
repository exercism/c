#include "luhn.h"
#include <stddef.h>
#include <string.h>
#include <ctype.h>

bool luhn(const char *num)
{
   if (num == NULL)
      return false;

   int pos = strlen(num) - 1;
   if (pos < 0)
      return false;

   int res = 0;
   int every_second = 0;
   int zeros = 0;
   while (pos >= 0) {
      if (isdigit(num[pos])) {
         char c = num[pos] - '0';
         zeros += (c == 0);
         if (every_second) {
            c *= 2;
            res += c > 9 ? c - 9 : c;
         } else {
            res += c;
         }
         every_second = !every_second;
      } else if (num[pos] != ' ') {
         return false;
      }
      pos--;
   }
   if (res == 0 && zeros == 1)
      return false;

   return (res % 10 == 0);
}
