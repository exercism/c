#include "pangram.h"
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_LETTERS (26)

bool is_pangram(const char *sentence)
{
   size_t sentence_length = ((sentence == NULL) ? 0 : strlen(sentence));
   bool found_letters[NUMBER_OF_LETTERS];

   memset(found_letters, 0, sizeof(found_letters));

   for (size_t i = 0; i < sentence_length; i++) {
      char letter = tolower(sentence[i]);

      if (isalpha(letter)) {
         found_letters[letter - 'a'] = true;
      }
   }

   for (size_t i = 0; i < NUMBER_OF_LETTERS; i++) {
      if (!found_letters[i]) {
         return false;
      }
   }

   return true;
}
