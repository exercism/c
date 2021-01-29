#include "binary.h"
#include <string.h>

int convert(const char *input)
{
   size_t input_len = strlen(input);
   int result = 0;
   for (size_t i = 0; i < input_len; i++) {
      result <<= 1;
      if (input[i] == '1') {
         result |= 1;
      } else if (input[i] != '0') {
         return -1;
      }
   }
   return result;
}
