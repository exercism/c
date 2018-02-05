#include <string.h>
#include <stdbool.h>
#include <stdio.h>

char *hey_bob(char *greeting)
{
   bool all_blank = true;
   bool all_shouty = true;
   bool any_letters = false;
   char final_char = '.';
   int i = 0;
   char ch = greeting[i];

   while (ch != 0) {
      if (all_blank)
         all_blank = ch == ' ' || (ch >= '\t' && ch <= '\r');

      if (all_shouty)
         all_shouty = !(ch >= 'a' && ch <= 'z');

      if (!any_letters)
         any_letters = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');

      if (ch != ' ')
         final_char = ch;

      i++;
      ch = greeting[i];
   }

   if (all_blank)
      return "Fine. Be that way!";

   if (all_shouty && any_letters && final_char == '?')
      return "Calm down, I know what I'm doing!";

   if (any_letters && all_shouty)
      return "Whoa, chill out!";

   if (final_char == '?')
      return "Sure.";

   return "Whatever.";
}
