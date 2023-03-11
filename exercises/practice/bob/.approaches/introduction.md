# Introduction

There are many ways to solve Bob.
Some approaches could involve a series of `if` statements or a `switch`.
An array can contain answers from which the right response is selected by an index calculated from scores given to the conditions.

## Approach: Answer array

**bob.h**

```c
#ifndef BOB_H
#define BOB_H

char const *hey_bob(char const *greeting);

#endif
```

**bob.c**

```c
#include "bob.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static char const *const answers[] = { "Whatever.", "Sure.", "Whoa, chill out!",
                                 "Calm down, I know what I'm doing!" };

char const *hey_bob(char const *greeting)
{
   if (!greeting || *greeting == '\0')
      return "Fine. Be that way!";
   char const *end_pos = greeting + strlen(greeting) - 1;
   while (end_pos > greeting && isspace(*end_pos))
      end_pos--;
   if (isspace(*end_pos))
      return "Fine. Be that way!";
   char const *msg = greeting;
   bool shout = true, has_letter = false;
   while (msg <= end_pos) {
      if (isalpha(*msg)) {
         has_letter = true;
         if (!isupper(*msg)) {
            shout = false;
            break;
         }
      }
      msg++;
   }
   int is_shout = shout && has_letter ? 2 : 0;
   int is_question = *end_pos == '?' ? 1 : 0;
   return answers[is_question + is_shout];
}
```

For more information, check the [Answer array approach][approach-answer-array].

[approach-answer-array]: https://exercism.org/tracks/c/exercises/bob/approaches/answer-array
