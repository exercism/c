#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "word_count.h"

// checks to see if we are counting a given word:
//    if word counted already it returns index.
//    elseo returns -1
static int word_match(char *testWord, int current_word_count, WordCount_Word_t words[MAX_WORDS])
{
   int index;
   int matchIndex = -1;

   for (index = 0; index < current_word_count; index++)
   {
      if (!strcmp(testWord, words[index].text))
      {
         matchIndex = index;
         break;
      }
   }
   return matchIndex;
}

int word_count(char *input_text, WordCount_Word_t words[MAX_WORDS])
{
   int index;
   int uniqueWords = 0;
   char *testWord;
   char *lowerCaseInputText;  // hold lowercase copy of passed text
   const char *delimiters = " ,.-\n:!!&@$%^&\"";

   // convert the input text to lower case
   lowerCaseInputText = malloc(strlen(input_text)+1);
   for(index=0; input_text[index] != 0; index++)
   {
      lowerCaseInputText[index] = tolower(input_text[index]);
   }
   lowerCaseInputText[index] = 0;

   // start with known results...
   memset(words, 0, sizeof(WordCount_Word_t));

   // todo parse string for words.
   testWord = strtok(lowerCaseInputText, delimiters);
   while(testWord != NULL)
   {
      // account for leading/trailing single quote.
      if (('\'' == testWord[0]) && ('\'' == testWord[strlen(testWord)-1]))
      {
         testWord[strlen(testWord)-1] = '\0';
         testWord++;
      }

      // determine index of counted word.
      index = word_match(testWord, uniqueWords, words);

      // if not yet counted....
      if (-1 == index)
      {
         words[uniqueWords].count = 1;
         strcpy(words[uniqueWords].text, testWord);
         uniqueWords++;
      }
      else
      {
         words[index].count++;
      }
      // next word in string
      testWord = strtok(NULL, delimiters);
   }

   free(lowerCaseInputText);
   return uniqueWords;
}
