#include "isogram.h"
#include <ctype.h>
#include <stddef.h>

bool isIsogram(const char phrase[])
{
   long usedLetters = 0;

   if (phrase == NULL)
      return false;

   for (int i = 0; phrase[i] != '\0'; ++i) {
      if (isalpha(phrase[i])) {
         int bitNumber = toupper(phrase[i]) - 'A';
         long bitMask = 1 << bitNumber;

         if ((usedLetters & bitMask) > 0)
            return false;
         else
            usedLetters |= bitMask;
      }
   }

   return true;
}
