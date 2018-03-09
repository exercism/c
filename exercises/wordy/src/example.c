#include "wordy.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct {
   const char *str;
   const size_t len;
} map_t;

static const map_t q_init = { "What is", 7 };

#define COMMANDS \
        CMD(+, "plus", 4) \
        CMD(-, "minus", 5) \
        CMD(*, "multiplied by", 13) \
        CMD(/, "divided by", 10)

bool answer(const char *question, int *result)
{
   if (question == NULL)
      return false;

   if (strncmp(q_init.str, question, q_init.len))
      return false;
   question += q_init.len;

   int chars_read;
   if (sscanf(question, " %d %n", result, &chars_read) != 1)
      return false;

   question += chars_read;

   while (*question != '?') {
      int tmp;

#define CMD(a, b, c) \
      if (strncmp(b, question, c) == 0) { \
         question += c; \
         if (sscanf(question, " %d %n", &tmp, &chars_read) != 1) \
            return false; \
         question += chars_read; \
         *result a##= tmp; \
      } else
      COMMANDS
#undef CMD
      {
         return false;
      }
   }

   return *++question == '\0';
}
