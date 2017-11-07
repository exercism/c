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

void anagrams_for(const char *word, struct candidates *candidates)
{
   char lower_word[MAX_STR_LEN] = { 0 };
   strncpy(&lower_word[0], word, MAX_STR_LEN);
   to_lower_case(&lower_word[0]);
   char sorted_word[MAX_STR_LEN] = { 0 };
   strncpy(&sorted_word[0], &lower_word[0], MAX_STR_LEN);
   qsort(&sorted_word, strlen(sorted_word), 1, compare);
   for (int i = 0; i < (int)candidates->count; i++) {
      char lower_candidate[MAX_STR_LEN] = { 0 };
      strncpy(&lower_candidate[0], candidates->candidate[i].candidate,
              MAX_STR_LEN);
      to_lower_case(&lower_candidate[0]);
      if (strcmp(&lower_candidate[0], &lower_word[0]) == 0) {
         candidates->candidate[i].is_anagram = NOT_ANAGRAM;
      }
      if (candidates->candidate[i].is_anagram == UNCHECKED) {
         qsort(&lower_candidate[0], strlen(&lower_candidate[0]), 1, compare);
         if (strcmp(&sorted_word[0], &lower_candidate[0]) == 0) {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
         } else {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
         }
      }
   }
}
