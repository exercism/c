# Look for start chars

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

