#include "reverse_string.h"
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value)
{
   size_t value_len = strlen(value);
   char *result = malloc(value_len + 1);
   char *dest = result + value_len;

   *dest = '\0';
   while (*value) {
      --dest;
      *dest = *value;
      ++value;
   }

   return result;
}
