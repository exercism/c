#include <stddef.h>
#include <string.h>
#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
   int count = -1;
   if (lhs && rhs && (strlen(lhs) == strlen(rhs))) {
      count = 0;
      int length = (int)strlen(lhs);
      for (int i = 0; i < length; ++i) {
         if (lhs[i] != rhs[i]) {
            ++count;
         }
      }
   }
   return count;
}
