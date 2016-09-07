#include "hamming.h"

int compute(char *lhs, int lhs_len, char *rhs, int rhs_len)
{
   int count = 0;
   int i = 0;
   for (i = 0; i < lhs_len && i < rhs_len; ++i) {
      if (lhs[i] != rhs[i]) {
         ++count;
      }
   }
   return count;
}
