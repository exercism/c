#include "crypto_square.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

/* mstrlen: get the length of input counting only alnums */
static size_t mstrlen(const char *input)
{
   size_t i = 0;
   while (*input != '\0') {
      if (isalnum(*input))
         i++;
      input++;
   }

   return i;
}

/* get_cols_and_rows: calculate columns and rows for the input square */
static void get_cols_and_rows_input(size_t len, size_t *cols_inp,
                                    size_t *rows_inp)
{
   *cols_inp = sqrt(len);

   while ((*cols_inp) * (*rows_inp = *cols_inp) < len)
      if (++(*cols_inp) * (*rows_inp) >= len)
         break;
}

/* get_pos_cipher: calculate the position in the cipher string */
static size_t get_pos_cipher(const size_t pos_inp, const size_t rows_inp,
                             const size_t cols_inp)
{
   return (pos_inp / cols_inp) + (pos_inp % cols_inp) * (rows_inp + 1);
}

char *ciphertext(const char *input)
{
   if (input == NULL)
      return NULL;
   if (*input == '\0')
      return calloc(1, 1);

   size_t len_inp = mstrlen(input);
   if (len_inp == 0)
      return calloc(1, 1);

   size_t cols_inp, rows_inp;
   get_cols_and_rows_input(len_inp, &cols_inp, &rows_inp);

   /* no need for extra row if single line */
   size_t len_out = rows_inp > 1
       ? (rows_inp + 1) * cols_inp : rows_inp * cols_inp;

   char *res = malloc(len_out + 1);
   if (res == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   size_t pos_inp = 0;
   while (*input != '\0') {
      if (isalnum(*input)) {
         size_t pos_cipher = get_pos_cipher(pos_inp, rows_inp, cols_inp);
         res[pos_cipher] = tolower(*input);
         pos_inp++;
      }
      input++;
   }

   /* fill to the end of the row */
   while (pos_inp % cols_inp != 0) {
      res[get_pos_cipher(pos_inp, rows_inp, cols_inp)] = ' ';
      pos_inp++;
   }

   /* fill the bottom row if any */
   if (rows_inp > 1)
      for (size_t i = 0; i < cols_inp; i++) {
         res[rows_inp * (i + 1) + i] = ' ';
      }

   res[(rows_inp > 1) ? len_out - 1 : len_out] = '\0';

   return res;
}
