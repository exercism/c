#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

bool is_isogram(const char phrase[])
{
   uint32_t used_letters = 0;

   if (phrase == NULL)
      return false;

   for (int16_t i = 0; phrase[i] != '\0'; ++i) {
      if (isalpha(phrase[i])) {
         uint8_t bit_number = toupper(phrase[i]) - 'A';
         uint32_t bit_mask = 1 << bit_number;

         if ((used_letters & bit_mask) > 0)
            return false;
         else
            used_letters |= bit_mask;
      }
   }

   return true;
}
