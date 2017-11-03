#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word_count.h"

// checks to see if we are counting a given word:
// if word counted already it returns index,
// else returns -1
static int word_match(char *testWord, int current_word_count,
                      word_count_word_t words[MAX_WORDS])
{
   int match_index = -1;

   for (int index = 0; index < current_word_count; index++) {
      if (!strcmp(testWord, words[index].text)) {
         match_index = index;
         break;
      }
   }
   return match_index;
}

int word_count(const char *input_text, word_count_word_t * words)
{
   int index;
   int unique_words = 0;
   char *test_word;
   char *lower_case_input_text; // hold lowercase copy of passed text
   const char *delimiters = " ,.-\n:!!&@$%^&\"";

   // convert the input text to lower case
   lower_case_input_text = malloc(strlen(input_text) + 1);
   for (index = 0; input_text[index] != 0; index++) {
      lower_case_input_text[index] = tolower(input_text[index]);
   }
   lower_case_input_text[index] = '\0';

   // start with known results...
   memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

   test_word = strtok(lower_case_input_text, delimiters);
   while (test_word != NULL) {
      // account for leading/trailing single quote.
      if (('\'' == test_word[0]) && ('\'' == test_word[strlen(test_word) - 1])) {
         test_word[strlen(test_word) - 1] = '\0';
         test_word++;
      }
      // determine index of counted word.
      index = word_match(test_word, unique_words, words);

      // add if not yet counted else increment count.
      if (-1 == index) {
         // reject anything that would overrun buffers
         if (MAX_WORD_LENGTH < strlen(test_word)) {
            unique_words = EXCESSIVE_LENGTH_WORD;
            break;
         }
         if (MAX_WORDS == unique_words) {
            unique_words = EXCESSIVE_NUMBER_OF_WORDS;
            break;
         }
         words[unique_words].count = 1;
         strncpy(words[unique_words].text, test_word, MAX_WORD_LENGTH);
         unique_words++;
      } else {
         words[index].count++;
      }
      // get next word in string
      test_word = strtok(NULL, delimiters);
   }

   free(lower_case_input_text);
   return unique_words;
}
