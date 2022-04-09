#include "diamond.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char **make_diamond(const char letter)
{
   if (!isalpha(letter))
      return NULL;

   const char letter_upper = toupper(letter);
   const size_t row_count = 2 * (letter_upper - 'A' + 1) - 1;
   const size_t col_count = row_count + 1;

   char **diamond = malloc(sizeof(char *) * row_count);
   if (diamond == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   char *all_rows = malloc(row_count * col_count);
   if (all_rows == NULL) {
      fprintf(stderr, "Memory error!\n");
      free(diamond);
      return NULL;
   }

   memset(all_rows, ' ', row_count * col_count);

   const size_t middle = row_count / 2;
   char curr_char = 'A';
   int advance = 1;
   for (size_t row = 0; row < row_count; row++) {
      diamond[row] = &all_rows[row * col_count];
      diamond[row][col_count - 1] = '\0';

      diamond[row][middle + (curr_char - 'A')] = curr_char;
      diamond[row][middle - (curr_char - 'A')] = curr_char;

      if (curr_char == letter_upper)
         advance = -1;
      curr_char += advance;
   }

   return diamond;
}

void free_diamond(char **diamond)
{
    free(diamond[0]);
    free(diamond);
}

