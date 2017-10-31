#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "anagram.h"

static void to_lower_case(char p[])
{
   char *tmp = p;
   while (*tmp) {
      *tmp = tolower(*tmp);
      tmp++;
   }
}

static int compare(const void *a, const void *b)
{
   return *(const char *)a - *(const char *)b;
}

void anagrams_for(char word[], struct candidates *candidates)
{
   to_lower_case(word);
   for (int i = 0; i < (int)candidates->count; i++) {
      to_lower_case(candidates->candidate[i].candidate);
      if (strcmp(word, candidates->candidate[i].candidate) == 0) {
         candidates->candidate[i].is_anagram = NOT_ANAGRAM;
      }
   }
   qsort(word, strlen(word), 1, compare);
   for (int i = 0; i < (int)candidates->count; i++) {
      if (candidates->candidate[i].is_anagram == UNCHECKED) {
         qsort(candidates->candidate[i].candidate,
               strlen(candidates->candidate[i].candidate), 1, compare);
         if (strcmp(word, candidates->candidate[i].candidate) == 0) {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
         } else {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
         }
      }
   }
}
