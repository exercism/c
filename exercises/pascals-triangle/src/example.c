#include "pascals_triangle.h"

void pt_free(size_t ** mem_block, size_t n)
{
   for (size_t i = 0; i < n; i++) {
      free(mem_block[i]);
   }
   free(mem_block);
}

size_t **pascals_triangle(char *count)
{
   if (count == NULL) {
      return (size_t **) NULL;
   }
   size_t **zero = (size_t **) calloc(1, sizeof(size_t *));
   zero[0] = (size_t *) calloc(1, sizeof(size_t));
   int i, j;
   int rows = atoi(count);
   if (!strcmp(count, "0")) {
      return zero;
   } else if (rows <= 0) {
      pt_free(zero, 1);
      return (size_t **) NULL;
   } else {
      pt_free(zero, 1);
   }
   size_t **result = (size_t **) calloc(rows, sizeof(size_t *));
   for (i = 0; i < rows; i++) {
      result[i] = (size_t *) calloc(rows, sizeof(size_t));
   }
   result[0][0] = 1;
   for (i = 1; i < rows; ++i) {
      result[i][0] = 1;
      for (j = 1; j <= i; ++j) {
         result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
      }
   }
   return result;
}
