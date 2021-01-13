#include "pascals_triangle.h"

void free_triangle(size_t ** mem_block, size_t n)
{
   for (size_t i = 0; i < n; i++) {
      free(mem_block[i]);
   }
   free(mem_block);
}

size_t **create_triangle(int rows)
{
   if (rows == 0) {
      size_t **zero = calloc(1, sizeof(size_t *));
      zero[0] = calloc(1, sizeof(size_t));
      return zero;
   } else if (rows < 0) {
      return NULL;
   }
   size_t **result = calloc(rows, sizeof(size_t *));
   for (int i = 0; i < rows; i++) {
      result[i] = calloc(rows, sizeof(size_t));
   }
   result[0][0] = 1;
   for (int i = 1; i < rows; ++i) {
      result[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
         result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
      }
   }
   return result;
}
