#include "isogram.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>

bool isIsogram(const char phrase[])
{
   uint32_t usedLetters = 0;

   if (phrase == NULL)
      return false;

   for (int16_t i = 0; phrase[i] != '\0'; ++i) {
      if (isalpha(phrase[i])) {
         uint8_t bitNumber = toupper(phrase[i]) - 'A';
         uint32_t bitMask = 1 << bitNumber;

         if ((usedLetters & bitMask) > 0)
            return false;
         else
            usedLetters |= bitMask;
      }
   }

   return true;
}
