#include "bracket_push.h"
#include <stdio.h>

static bool is_matching(char a, char b)
{
   if (a == '{')
      return b == '}';
   if (a == '[')
      return b == ']';
   if (a == '(')
      return b == ')';

   return false;
}

static bool is_opening(const char c)
{
   return (c == '{') || (c == '[') || (c == '(');
}

static bool is_closing(const char c)
{
   return (c == '}') || (c == ']') || (c == ')');
}

/* https://stackoverflow.com/a/2718114/6049386 */
static const char *match(const char *str)
{
   if (*str == '\0' || is_closing(*str))
      return str;

   if (is_opening(*str)) {
      const char *closer = match(str + 1);

      if (is_matching(*str, *closer))
         return match(closer + 1);

      return str;
   }

   return match(++str);
}

bool is_paired(const char *input)
{
   if (input == NULL) {
      return true;
   }

   const char *res = match(input);
   return (*res == '\0');
}
