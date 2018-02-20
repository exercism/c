#include "bracket_push.h"
#include <stdio.h>

static bool is_bbp(char c)
{
   return (c == '{') || (c == '}') ||
       (c == '[') || (c == ']') || (c == '(') || (c == ')');
}

static bool matching(char a, char b)
{
   if (a == '}')
      return b == '{';
   if (a == ']')
      return b == '[';
   if (a == ')')
      return b == '(';

   return false;
}

bool bbp_okay(const char *input)
{
   if (input == NULL || *input == '\0') {
      return true;
   }

   char stack[MAXBBP] = { 0 };
   int top = 0;

   char *tmp = (char *)input;
   while (*tmp) {
      if (is_bbp(*tmp)) {
         stack[top] = *tmp;

         if (top == MAXBBP) {
            fprintf(stderr, "Input too long.\n");
            return false;
         }

         while ((top > 0) && matching(stack[top], stack[top - 1]))
            top -= 2;

         top++;
      }
      tmp++;
   }

   return top == 0;
}
