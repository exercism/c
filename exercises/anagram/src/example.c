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

void find_anagrams(const char *subject, struct candidates *candidates)
{
   char lower_subject[MAX_STR_LEN] = { 0 };
   strncpy(&lower_subject[0], subject, MAX_STR_LEN);
   to_lower_case(&lower_subject[0]);
   char sorted_subject[MAX_STR_LEN] = { 0 };
   strncpy(&sorted_subject[0], &lower_subject[0], MAX_STR_LEN);
   qsort(&sorted_subject, strlen(sorted_subject), 1, compare);
   for (int i = 0; i < (int)candidates->count; i++) {
      char lower_candidate[MAX_STR_LEN] = { 0 };
      strncpy(&lower_candidate[0], candidates->candidate[i].word, MAX_STR_LEN);
      to_lower_case(&lower_candidate[0]);
      if (strcmp(&lower_candidate[0], &lower_subject[0]) == 0) {
         candidates->candidate[i].is_anagram = NOT_ANAGRAM;
      }
      if (candidates->candidate[i].is_anagram == UNCHECKED) {
         qsort(&lower_candidate[0], strlen(&lower_candidate[0]), 1, compare);
         if (strcmp(&sorted_subject[0], &lower_candidate[0]) == 0) {
            candidates->candidate[i].is_anagram = IS_ANAGRAM;
         } else {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
         }
      }
   }
}
