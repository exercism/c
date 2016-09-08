#include <string.h>
#include <stdbool.h>
#include <stdio.h>

char *hey_bob(char *greeting)
{
   bool all_blank = true;
   bool all_shouty = true;
   bool any_letters = false;
   bool letter_char = false;
   char final_char = '.';
   int i = 0;
   char ch = greeting[i];

   while (ch != 0) {

      if (all_blank)
         all_blank = ch == ' ';

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

   if (any_letters && all_shouty)
      return "Whoa, chill out!";

   if (final_char == '?')
      return "Sure.";

   return "Whatever.";
}
