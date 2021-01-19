#include <stdlib.h>
#include "pascals_triangle.h"

void free_triangle(uint8_t ** triangle, size_t rows)
{
   for (size_t i = 0; i < rows; i++)
      free(triangle[i]);

   free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
   uint8_t **triangle;

   if (rows == 0) {
      if (!(triangle = calloc(1, sizeof(uint8_t *))))
         return NULL;

      if (!(triangle[0] = calloc(1, sizeof(uint8_t)))) {
         free(triangle);
         return NULL;
      }

   } else {
      if (!(triangle = calloc(rows, sizeof(uint8_t *))))
         return NULL;

      for (size_t i = 0; i < rows; i++) {
         if (!(triangle[i] = calloc(rows, sizeof(uint8_t)))) {
            free_triangle(triangle, i);
            return NULL;
         }
      }

      triangle[0][0] = 1;
      for (size_t i = 1; i < rows; ++i) {
         triangle[i][0] = 1;
         for (size_t j = 1; j <= i; ++j) {
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
         }
      }
   }
   return triangle;
}
