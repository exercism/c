#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "anagram.h"

void to_lower_case(char p[])
{
   char *tmp = p;
   while (*tmp) {
      *tmp = tolower(*tmp);
      tmp++;
   }
}

int compare(const void *a, const void *b)
{
   return *(const char *)a - *(const char *)b;
}

void anagrams_for(char word[], struct candidates *candidates)
{
   to_lower_case(word);
   for (int x = 0; x < candidates->size; x++) {
      to_lower_case(candidates->candidate[x].candidate);
      if (strcmp(word, candidates->candidate[x].candidate) == 0) {
         candidates->candidate[x].isAnagram = NOT_ANAGRAM;
      }
   }
   qsort(word, strlen(word), 1, compare);
   for (int x = 0; x < candidates->size; x++) {
      if (candidates->candidate[x].isAnagram == UNCHECKED) {
         qsort(candidates->candidate[x].candidate,
               strlen(candidates->candidate[x].candidate), 1, compare);
         if (strcmp(word, candidates->candidate[x].candidate) == 0) {
            candidates->candidate[x].isAnagram = IS_ANAGRAM;
         } else {
            candidates->candidate[x].isAnagram = NOT_ANAGRAM;
         }
      }
   }
}
