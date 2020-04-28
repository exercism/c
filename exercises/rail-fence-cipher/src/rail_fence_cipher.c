#include "rail_fence_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void pattern(char *string, size_t len)
{
   for (size_t i = 0; i < len; i++) {
      if (string[i])
         putchar('*');
      else
         putchar('-');
   }
   putchar('\n');
}

char *encode(char *text, size_t rails)
{
   size_t length = strlen(text);
   char *ciphertext = (char *)calloc(length + 1, sizeof(char));
   size_t cell_size = 2 * rails - 2;
   if (!cell_size) {            // kludge
      strcpy(ciphertext, text);
      return ciphertext;
   }
   size_t j = 0;
   for (size_t rail = 0; rail < rails; rail++) {
      for (size_t i = 0; i < length; i += cell_size) {
         if (i + rail < length)
            ciphertext[j++] = text[i + rail];
         if (rail > 0 && rail < rails - 1) {
            if (i + rails + rail < length)
               ciphertext[j++] = text[i + cell_size - rail];
         }
      }
   }
   return ciphertext;
}

char *decode(char *ciphertext, size_t rails)
{
   size_t length = strlen(ciphertext);
   char *text = (char *)calloc(length + 1, sizeof(char));
   size_t cell_size = 2 * rails - 2;
   if (!cell_size) {            // kludge
      strcpy(text, ciphertext);
      return text;
   }
   size_t j = 0;
   for (size_t i = 0; i < length; i += cell_size) {
      text[i] = ciphertext[j++];
   }
   for (size_t rail = 1; rail < rails - 1; rail++) {
      for (size_t i = 0; i < length; i += cell_size) {
         if (i + rail < length)
            text[i + rail] = ciphertext[j++];
         if (i + cell_size - rail < length)
            text[i + cell_size - rail] = ciphertext[j++];
      }
   }
   for (size_t i = 0; i < length; i += cell_size) {
      if (i + rails - 1 < length)
         text[i + rails - 1] = ciphertext[j++];
   }
   return text;
}
