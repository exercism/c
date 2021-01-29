#include "run_length_encoding.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

enum rw_mode { READ, WRITE };

/* count_digits: return the count of digits in a number */
static size_t count_digits(size_t num)
{
   return log10(num) + 1;
}

/**
 * enc_helper: calculate the encoded size of 'text';
 *             encode in 'encoded' if write mode is set
 */
static size_t enc_helper(char *encoded, const char *text,
                         const enum rw_mode mode)
{
   size_t enc_len = 0;
   while (*text) {
      /* smallest count means a single char */
      size_t count = 1;
      while (*text == *(text + 1)) {
         count++;
         text++;
      }
      if (count > 1) {
         const size_t cdigits = count_digits(count);
         enc_len += cdigits;
         if (mode == WRITE) {
            sprintf(encoded, "%zu", count);
            encoded += cdigits;
         }
      }
      if (mode == WRITE)
         *encoded++ = *text;

      enc_len++;
      text++;
   }

   return enc_len;
}

/**
 * dec_helper: calculate the decoded size of 'data';
 *             decode in 'decoded' if write mode is set
 */
static size_t dec_helper(char *decoded, const char *data,
                         const enum rw_mode mode)
{
   size_t dec_len = 0;
   while (*data) {
      while (*data && !isdigit(*data)) {
         dec_len++;
         if (mode == WRITE)
            *decoded++ = *data;
         data++;
      }
      size_t count = 0;
      while (isdigit(*data)) {
         count = count * 10 + *data - '0';
         data++;
      }
      for (size_t i = 0; i < count; i++) {
         dec_len++;
         if (mode == WRITE)
            *decoded++ = *data;
      }
      if (*data != '\0')
         data++;
   }

   return dec_len;
}

char *encode(const char *text)
{
   if (text == NULL)
      return NULL;
   if (*text == '\0')
      return calloc(1, 1);

   /* get length */
   const size_t enc_len = enc_helper(NULL, text, READ);
   if (enc_len == 0)
      return NULL;

   char *encoded = malloc(enc_len + 1);
   if (encoded == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   /* encode */
   enc_helper(encoded, text, WRITE);
   encoded[enc_len] = '\0';

   return encoded;
}

char *decode(const char *data)
{
   if (data == NULL)
      return NULL;
   if (*data == '\0')
      return calloc(1, 1);

   /* get length */
   const size_t dec_len = dec_helper(NULL, data, READ);

   char *decoded = malloc(dec_len + 1);
   if (decoded == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   /* decode */
   dec_helper(decoded, data, WRITE);
   decoded[dec_len] = '\0';

   return decoded;
}
