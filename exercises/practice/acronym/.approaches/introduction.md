# Introduction

There are many ways to solve Acronym.
One approach is to look for characters that signal an upcoming initial.

## General guidance

Some approaches make special conditions for characters like an apostrophe and/or an underscore.
It might be helpful to not focus on corner cases, but to focus on what characters are reliable indicators of what you're looking for.

## Approach: Look for start chars

**acronym.h**

```c
#ifndef ACRONYM_H
#define ACRONYM_H

char *abbreviate(const char *phrase);

#endif
```

**acronym.c**

```c
#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase)
{
   if (!phrase || !(*phrase))
      return NULL;

   char *acronyms = malloc(strlen(phrase) + 1);
   if (!acronyms)
      return NULL;
   char *acronyms_start = acronyms;

   const char start_trigger[] = " -";
   for (int start = 1; *phrase; phrase++) {
      if (start && isalpha(*phrase)) {
         *acronyms++ = toupper(*phrase);
         start = 0;
      } else if (strchr(start_trigger, *phrase))
         start = 1;
   }
   *acronyms = '\0';
   return acronyms_start;
}
```

For more information, check the [Look for start chars approach][approach-look-for-start-chars].

[approach-look-for-start-chars]: https://exercism.org/tracks/c/exercises/acronym/approaches/look-for-start-chars
