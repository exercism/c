#include "pangram.h"
#include <string.h>

#define NUMBER_OF_LETTERS (26)
#define DOWNCASE(letter) ((letter >= 'A') && (letter <= 'Z')) ? letter + ('a' - 'A') : letter

bool is_pangram(const char *sentence) {
   int sentence_length = strlen(sentence);
   char found_letters[NUMBER_OF_LETTERS];
   int i;

   memset(found_letters, 0, sizeof(found_letters));

   for(i = 0; i < sentence_length; i++) {
      char letter = DOWNCASE(sentence[i]);

      if((letter >= 'a') && letter <= 'z') {
         found_letters[letter - 'a']++;
      }
   }

   for(i = 0; i < NUMBER_OF_LETTERS; i++) {
      if(found_letters[i] == 0) {
         return false;
      }
   }

   return true;
}
