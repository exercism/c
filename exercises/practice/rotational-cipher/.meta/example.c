#include "rotational_cipher.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key)
{
   char *rotated = malloc(strlen(text) + 1);
   char *out = rotated;
   for (const char *in = text; *in != '\0'; ++in, ++out) {
      if (isalpha(*in)) {
         const char base = isupper(*in) ? 'A' : 'a';
         *out = base + ((*in - base + shift_key) % 26);
      } else {
         *out = *in;
      }
   }
   *out = '\0';
   return rotated;
}
