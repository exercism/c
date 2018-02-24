#include "crypto_square.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

/* mstrlen: get the length of input counting only alnums */
static int mstrlen(const char *input)
{
   int i = 0;
   while (*input) {
      if (isalnum(*input))
         i++;
      input++;
   }

   return i;
}

/* get_cols_and_rows: calculate columns and rows from len */
static void get_cols_and_rows(int len, int *cols, int *rows)
{
   *cols = sqrt(len);

   if (*cols * *cols == len) {
      *rows = *cols;
   } else if (*cols * (*cols + 1) >= len) {
      *rows = *cols;
      (*cols)++;
   } else {
      (*cols)++;
      *rows = *cols;
      if ((*cols * *cols) < len)
         (*cols)++;
   }
}

/* get_pos_cipher: calculate the position in the cipher string */
static int get_pos_cipher(const int pos_inp, const int rows, const int cols)
{
   return (pos_inp / cols) + (pos_inp % cols) * (rows + 1);
}

char *ciphertext(const char *input)
{
   if (input == NULL)
      return NULL;
   if (*input == '\0')
      return calloc(1, 1);

   int len_inp = mstrlen(input);
   if (len_inp == 0)
      return calloc(1, 1);

   int cols, rows;
   get_cols_and_rows(len_inp, &cols, &rows);

   /* no need for extra row if single line */
   int len_out = rows > 1 ? (rows + 1) * cols : rows * cols;

   char *res = malloc(len_out + 1);
   if (res == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   int pos_inp = 0;
   while (*input) {
      if (isalnum(*input)) {
         int pos_cipher = get_pos_cipher(pos_inp, rows, cols);
         res[pos_cipher] = tolower(*input);
         pos_inp++;
      }
      input++;
   }

   /* fill to the end of the row */
   while (pos_inp % cols != 0) {
      res[get_pos_cipher(pos_inp, rows, cols)] = ' ';
      pos_inp++;
   }

   /* fill the bottom row if any */
   if (rows > 1)
      for (int i = 0; i < cols; i++) {
         res[rows * (i + 1) + i] = ' ';
      }

   res[(rows > 1) ? len_out - 1 : len_out] = '\0';

   return res;
}
