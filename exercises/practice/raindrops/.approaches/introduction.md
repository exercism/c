# Introduction

There are various idioomatic ways to solve Raindrops.
A straightforward and approach is to use a series of `if` statements.
Another approach could look up both factors and raindrop sounds from an array, using data-driven programming to make the code as simple as possible.

## General Guidance

The key to solving Raindrops is to know if the input is evenly divisible by `3`, `5` and/or `7` using the [modulo operator][modulo-operator].

## Assumptions

- `drops` is a non-negative, 32-bit integer (from `0` to `2,147,483,647`).
- `result` has enough space to hold the largest output string, meaning 16 bytes:
  - 15 bytes for `"PlingPlangPlong"`, plus one for the null terminating character;
  - 10 bytes for the largest possible value of `drops`, plus one for `'\0'`.
- `result` has been initialized as an empty string (that is, `result[0]` is `'\0'`).

## Approach: `if` Statements

**raindrops.h**

```c
#ifndef RAINDROPS_H
#define RAINDROPS_H

void convert(char result[], int drops);

#endif
```

**raindrops.c**

```c
#include "raindrops.h"

#include <stdio.h>
#include <string.h>

void convert(char result[], int drops)
{
   if (drops % 3 == 0)
      strcat(result, "Pling");
   if (drops % 5 == 0)
      strcat(result, "Plang");
   if (drops % 7 == 0)
      strcat(result, "Plong");

   if (strlen(result) == 0)
      sprintf(result, "%d", drops);
}
```

This approach uses a series of `if`-statements and string concatentation to build up the result string.
For more information, check the [`if` statements approach][approach-if-statements].

## Approach: `sprintf` Function

**raindrops.h**

```c
#ifndef RAINDROPS_H
#define RAINDROPS_H

void convert(char result[], int drops);

#endif
```

**raindrops.c**

```c
#include "raindrops.h"

#include <stdio.h>
#include <string.h>

void convert(char result[], int drops)
{
   sprintf(result, "%s%s%s", drops % 3 == 0 ? "Pling" : "",
           drops % 5 == 0 ? "Plang" : "", drops % 7 == 0 ? "Plong" : "");

   if (strlen(result) == 0)
      sprintf(result, "%d", drops);
}
```

This approach uses a single call to the [`sprintf` function][sprintf] to build the result string;
it contains a series of [ternary conditional operators][conditional-opeator].
For more information, check the [`sprintf` functon approach][approach-sprintf].

## Approach: Data-Driven Programming

**raindrops.h**

```c
#ifndef RAINDROPS_H
#define RAINDROPS_H

void convert(char result[], int drops);

#endif
```

**raindrops.c**

```c
#include "raindrops.h"

#include <stdio.h>
#include <string.h>

typedef struct {
   int factor;
   const char *sound;
} sound_t;

static const sound_t SOUNDS[] = {
   { 3, "Pling" },
   { 5, "Plang" },
   { 7, "Plong" },
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void convert(char result[], int drops)
{
   for (size_t i = 0; i < ARRAY_SIZE(SOUNDS); i++) {
      if (drops % SOUNDS[i].factor == 0) {
         strcat(result, SOUNDS[i].sound);
      }
   }

   if (strlen(result) == 0) {
      sprintf(result, "%d", drops);
   }
}
```

This approach puts some of the logic into data, simplifying the code.
For more information, check the [data-driven approach][approach-data-driven].

[modulo-operator]: https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/
[conditional-operator]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c/
[sprintf]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/sprintf.html
[approach-if-statements]: https://exercism.org/tracks/c/exercises/raindrops/approaches/if-statements
[approach-sprintf]: https://exercism.org/tracks/c/exercises/raindrops/approaches/sprintf
[approach-data-driven]: https://exercism.org/tracks/c/exercises/raindrops/approaches/data-driven
