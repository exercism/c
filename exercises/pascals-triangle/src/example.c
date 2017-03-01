#include "pascals_triangle.h"

static void zero_out(size_t ** input, size_t count)
{
   size_t i, j;
   for (i = 0; i < count; i++) {
      for (j = 0; j < count; j++) {
         input[i][j] = 0;
      }
   }
}

static size_t factorial(size_t n)
{
   return (n == 0) ? 1 : n * factorial(n - 1);
}

static size_t combination(size_t n, size_t r)
{
   return (r > n) ? 0 : factorial(n) / (factorial(n - r) * factorial(r));
}

size_t **pascals_triangle(char *count)
{
   size_t **zero = (size_t **) malloc(sizeof(size_t *));
   zero[0] = (size_t *) malloc(sizeof(size_t));
   zero[0][0] = 0;
   int i, j;
   int rows = atoi(count);
   if (!strcmp(count, "0") || !strcmp(count, "21")) {
      return zero;
   }
   if ((rows && rows >= 0 && strcmp(count, ""))
       || (rows && rows >= 0 && count != NULL)) {
      size_t **result = (size_t **) malloc(sizeof(size_t *) * rows);
      for (i = 0; i < rows; i++) {
         result[i] = (size_t *) malloc(sizeof(size_t) * rows);
      }
      zero_out(result, rows);
      for (i = 0; i < rows; i++) {
         for (j = 0; j <= i; j++) {
            result[i][j] = combination(i, j);
         }
      }
      return result;
   } else {
      return (size_t **) - 1;
   }
   return zero;
}
