#include "minesweeper.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void set_single_field(char **minefield, const size_t row,
                             const size_t col)
{
   if (minefield[row][col] == '*')
      return;

   const char c = minefield[row][col];
   minefield[row][col] = (c == ' ') ? '1' : c + 1;
}

static void set_fields(char **minefield, const size_t all_rows,
                       const size_t all_cols, const size_t row,
                       const size_t col)
{
   const size_t from_row = row ? row - 1 : row;
   const size_t to_row = (row + 1 < all_rows) ? row + 1 : row;
   const size_t from_col = col ? col - 1 : col;
   const size_t to_col = (col + 1 < all_cols) ? col + 1 : col;

   for (size_t i = from_row; i <= to_row; i++) {
      for (size_t k = from_col; k <= to_col; k++)
         set_single_field(minefield, i, k);
   }
}

char **annotate(const char **minefield, const size_t rows)
{
   if (minefield == NULL || *minefield == NULL || rows == 0)
      return NULL;

   const size_t cols = strlen(minefield[0]);

   char **annotated = malloc(sizeof(char *) * rows);
   if (annotated == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   for (size_t i = 0; i < rows; i++) {
      annotated[i] = malloc(cols + 1);
      if (annotated[i] == NULL) {
         fprintf(stderr, "Memory error!\n");
         free(annotated);
         return NULL;
      }
      strcpy(annotated[i], minefield[i]);
   }

   for (size_t i = 0; i < rows; i++) {
      for (size_t k = 0; k < cols; k++) {
         if (minefield[i][k] == '*')
            set_fields(annotated, rows, cols, i, k);
         else if (minefield[i][k] != ' ' && !isdigit(minefield[i][k]))
            fprintf(stderr, "Invalid input: \"%c\" at "
                    "row %ld column %ld.\n", minefield[i][k], i, k);
      }
   }

   return annotated;
}
