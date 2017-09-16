#include <stddef.h>
#include <string.h>
#include "hamming.h"

size_t compute(const char *lhs, const char *rhs)
{
   size_t count = -1;
   if ( lhs && rhs && (strlen(lhs)==strlen(rhs))){
      count++;
      size_t lhs_len = strlen(lhs);
      size_t i = 0;
      for (i = 0; i < lhs_len; ++i) {
         if (lhs[i] != rhs[i]) {
            ++count;
         }
      }
   }
   return count;
}
