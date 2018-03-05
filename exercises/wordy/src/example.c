#include "wordy.h"
#include <string.h>
#include <ctype.h>

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

static void skip_space(const char **str)
{
   while (*(*str) == ' ')
      (*str)++;
}

static bool get_int(const char **str, int *i)
{
   skip_space(str);
   size_t int_len = 0;
   *i = 0;
   int sign = 1;
   if (*(*str) == '-') {
      sign = -1;
      (*str)++;
   }
   while (*(*str) && isdigit(*(*str))) {
      int_len++;
      (*i) = (*i) * 10 + *(*str) - '0';
      (*str)++;
   }
   (*i) *= sign;
   return (int_len != 0);
}

bool answer(const char *question, int *result)
{
   if (question == NULL)
      return false;

   if (strncmp(q_init.str, question, q_init.len))
      return false;
   question += q_init.len;

   if (!get_int(&question, result))
      return false;

   while (*question != '?') {
      skip_space(&question);
      int tmp;

#define CMD(a, b, c) \
      if (strncmp(b, question, c) == 0) { \
         question += c; \
         if (!get_int(&question, &tmp)) \
            return false; \
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
