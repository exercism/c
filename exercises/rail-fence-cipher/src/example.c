#include "rail_fence_cipher.h"
#include <string.h>
#include <stdlib.h>

char *encode(char *msg, size_t rails)
{
   size_t length = strlen(msg);
   char *ciphertext = (char *)calloc(length + 1, sizeof(char));
   size_t cell_size = 2 * rails - 2;
   if (cell_size == 0) {
      strcpy(ciphertext, msg);
      return ciphertext;
   }
   size_t j = 0;
   for (size_t rail = 0; rail < rails; rail++) {
      for (size_t i = 0; i < length; i += cell_size) {
         if (i + rail < length)
            ciphertext[j++] = msg[i + rail];
         if (rail > 0 && rail < rails - 1) {
            if (i + rails + rail < length)
               ciphertext[j++] = msg[i + cell_size - rail];
         }
      }
   }
   return ciphertext;
}

char *decode(char *ciphertext, size_t rails)
{
   size_t length = strlen(ciphertext);
   char *text = calloc(length + 1, sizeof(char));
   size_t cell_size = 2 * rails - 2;
   if (cell_size == 0) {
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
