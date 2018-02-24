#include "say.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

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

   const char *below_10[] = {
      "", "one", "two", "three", "four",
      "five", "six", "seven", "eight", "nine"
   };
   const int below_10_len[] = {
      0, 3, 3, 5, 4,
      4, 3, 5, 5, 4
   };

   const char *below_20[] = {
      "ten", "eleven", "twelve", "thirteen", "fourteen",
      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
   };
   const int below_20_len[] = {
      3, 6, 6, 8, 8,
      7, 7, 9, 8, 8
   };

   const char *below_100[] = {
      "", "", "twenty", "thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety"
   };
   const int below_100_len[] = {
      0, 0, 6, 6, 5,
      5, 5, 7, 6, 6
   };

   const char *thousands[] = {
      "", "thousand", "million", "billion"
   };
   const int thousands_len[] = {
      0, 8, 7, 7
   };

   /* below_20's are like two times below_10's so this will work */
   const int widest = 8;

   /* digits count */
   int digits = floor(log10(input)) + 1;

   /* take care of spaces/hyphens, thousends and termination */
   *ans = malloc((widest + 1) * (digits + (digits + 1) / 3) + 1);
   if (*ans == NULL) {
      fprintf(stderr, "Memory error!\n");
      return -1;
   }

   char *head = *ans;
   while (input) {

      int64_t tmp;
      int64_t order = pow(1000, (digits - 1) / 3);
      tmp = input / order;
      input -= tmp * order;

      while (tmp) {

         if (tmp / 100) {
            int i = tmp / 100;
            strcpy(head, below_10[i]);
            head += below_10_len[i];

            *head++ = ' ';

            strcpy(head, "hundred");
            head += 7;

            if (tmp -= i * 100)
               *head++ = ' ';
         }

         if (tmp < 10) {
            strcpy(head, below_10[tmp]);
            head += below_10_len[tmp];

            tmp = 0;

            digits--;

         } else if (tmp < 20) {
            tmp -= 10;
            strcpy(head, below_20[tmp]);
            head += below_20_len[tmp];

            tmp = 0;

            digits -= 2;

         } else {
            int i = tmp / 10;
            strcpy(head, below_100[i]);
            head += below_100_len[i];

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

      strcpy(head, thousands[digits / 3]);
      head += thousands_len[digits / 3];

      if (input)
         *head++ = ' ';

   }
   *head = '\0';

   /* success */
   return 0;
}
