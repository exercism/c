#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

typedef struct {
   int size;
   int **matrix;
} spiral_matrix_t;

spiral_matrix_t *spiral_matrix_create(int size);
void spiral_matrix_destroy(spiral_matrix_t *spiral_matrix);

#endif
