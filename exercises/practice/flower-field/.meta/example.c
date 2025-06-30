#include "flower_field.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void set_single_field(char **garden, const size_t row, const size_t col)
{
   if (garden[row][col] == '*')
      return;

   const char c = garden[row][col];
   garden[row][col] = (c == ' ') ? '1' : c + 1;
}

static void increment_neighbors(char **garden, const size_t row_count,
                                const size_t col_count, const size_t row,
                                const size_t col)
{
   const size_t from_row = row ? row - 1 : row;
   const size_t to_row = (row + 1 < row_count) ? row + 1 : row;
   const size_t from_col = col ? col - 1 : col;
   const size_t to_col = (col + 1 < col_count) ? col + 1 : col;

   for (size_t i = from_row; i <= to_row; i++) {
      for (size_t k = from_col; k <= to_col; k++)
         set_single_field(garden, i, k);
   }
}

char **annotate(const char **garden, const size_t rows)
{
   if (garden == NULL || *garden == NULL || rows == 0)
      return NULL;

   const size_t cols = strlen(garden[0]);

   char **annotated = malloc(sizeof(char *) * rows);
   if (annotated == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   char *all_rows = malloc(rows * (cols + 1));
   if (all_rows == NULL) {
      fprintf(stderr, "Memory error!\n");
      free(annotated);
      return NULL;
   }

   for (size_t i = 0; i < rows; i++) {
      annotated[i] = &all_rows[i * (cols + 1)];
      strcpy(annotated[i], garden[i]);
   }

   for (size_t i = 0; i < rows; i++) {
      for (size_t k = 0; k < cols; k++) {
         if (garden[i][k] == '*')
            increment_neighbors(annotated, rows, cols, i, k);
      }
   }

   return annotated;
}

void free_annotation(char **annotation)
{
   free(annotation[0]);
   free(annotation);
}
