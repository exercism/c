#include "say.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct {
   const char *name;
   size_t size;
} map_t;

/* *INDENT-OFF* */
static const map_t below_10[] = {
   {"", 0},          {"one", 3},       {"two", 3},       {"three", 5},
   {"four", 4},      {"five", 4},      {"six", 3},       {"seven", 5},
   {"eight", 5},     {"nine", 4}
};

static const map_t below_20[] = {
   {"ten", 3},       {"eleven", 6},    {"twelve", 6},    {"thirteen", 8},
   {"fourteen", 8},  {"fifteen", 7},   {"sixteen", 7},   {"seventeen", 9},
   {"eighteen", 8},  {"nineteen", 8}
};

static const map_t below_100[] = {
   {"", 0},          {"", 0},          {"twenty", 6},    {"thirty", 6},
   {"forty", 5},     {"fifty", 5},     {"sixty", 5},     {"seventy", 7},
   {"eighty", 6},    {"ninety", 6}
};

static const map_t thousands[] = {
   {"", 0},          {"thousand", 8},  {"million", 7},   {"billion", 7}
};
/* *INDENT-ON* */

/* below_20's are like two times below_10's so this will work */
static const int widest = 8;

static void advance_pos(char **dst, const char *src, size_t size)
{
   strcpy(*dst, src);
   *dst += size;
}

int say(int64_t input, char **ans)
{
   if (input < 0 || input > 999999999999 || ans == NULL)
      return -1;

   /* 'zero' is a corner case */
   if (input == 0) {
      *ans = malloc(5);
      if (*ans == NULL) {
         fprintf(stderr, "Memory error!/n");
         return -1;
      }
      strcpy(*ans, "zero");
      return 0;
   }

   /* digits count */
   int digits = floor(log10(input)) + 1;

   /* reserve space for space/hyphen */
   const size_t max_word = widest + 1;

   /* we add words from 'map_t thousands' every 3 digits */
   const size_t count_words = digits + (digits + 1) / 3;

   *ans = malloc(max_word * count_words + 1);
   if (*ans == NULL) {
      fprintf(stderr, "Memory error!\n");
      return -1;
   }

   char *head = *ans;
   while (input) {
      int64_t tmp;

      /* process in chunks of up to 3 digits */
      int64_t order = pow(1000, (digits - 1) / 3);
      tmp = input / order;
      input -= tmp * order;

      while (tmp) {
         if (tmp / 100) {
            int i = tmp / 100;
            advance_pos(&head, below_10[i].name, below_10[i].size);

            *head++ = ' ';

            advance_pos(&head, "hundred", 7);

            if (tmp -= i * 100)
               *head++ = ' ';
         }
         if (tmp < 10) {
            advance_pos(&head, below_10[tmp].name, below_10[tmp].size);

            tmp = 0;
            digits--;

         } else if (tmp < 20) {
            tmp -= 10;
            advance_pos(&head, below_20[tmp].name, below_20[tmp].size);

            tmp = 0;
            digits -= 2;

         } else {
            int i = tmp / 10;
            advance_pos(&head, below_100[i].name, below_100[i].size);

            tmp -= i * 10;
            digits--;

            if (tmp) {
               *head++ = '-';
               continue;
            }
         }
         if (tmp)
            *head++ = ' ';
      }

      /* cases with '0' at the end */
      while (digits % 3 != 0)
         digits--;

      if (digits)
         *head++ = ' ';

      advance_pos(&head, thousands[digits / 3].name,
                  thousands[digits / 3].size);

      if (input)
         *head++ = ' ';

   }
   *head = '\0';

   /* success */
   return 0;
}
