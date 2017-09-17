#include <stddef.h>
#include <string.h>
#include "hamming.h"

size_t compute(const char *lhs, const char *rhs)
{
   size_t count = -1;
   if (lhs && rhs && (strlen(lhs) == strlen(rhs))) {
      count = 0;
      for (size_t i = 0; i < strlen(lhs); ++i) {
         if (lhs[i] != rhs[i]) {
            ++count;
         }
      }
   }
   return count;
}
