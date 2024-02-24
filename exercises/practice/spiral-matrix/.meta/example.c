#include <stdlib.h>
#include "spiral_matrix.h"

spiral_matrix_t *spiral_matrix_create(int size)
{
   spiral_matrix_t *spiral = calloc(1, sizeof(spiral_matrix_t));
   spiral->size = size;

   if (size == 0) {
      return spiral;
   }

   spiral->matrix = calloc(size, sizeof(int *));
   for (int i = 0; i < size; i++) {
      spiral->matrix[i] = calloc(size, sizeof(int));
   }

   int x = 0;
   int y = 0;
   int dx = 1;
   int dy = 0;

   for (int i = 1; i <= size * size; i++) {
      spiral->matrix[y][x] = i;
      if (x + dx >= size || x + dx < 0 || y + dy >= size || y + dy < 0 ||
          spiral->matrix[y + dy][x + dx] != 0) {
         int new_dx = -dy;
         int new_dy = dx;
         dx = new_dx;
         dy = new_dy;
      }
      x += dx;
      y += dy;
   }

   return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *spiral)
{
   for (int i = 0; i < spiral->size; i++) {
      free(spiral->matrix[i]);
   }

   if (spiral->size > 0) {
      free(spiral->matrix);
   }

   free(spiral);
}
