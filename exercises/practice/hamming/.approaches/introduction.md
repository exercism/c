# Introduction

There are many ways to solve Hamming.
One way is to increment the pointers directly and compare them.

## Approach: Increment pointers

**hamming.h**

```c
#ifndef HAMMING_H
#define HAMMING_H

int compute(const char *lhs, const char *rhs);

#endif
```

**hamming.c**

```c
#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
   if (!lhs || !rhs)
      return -1;

   int distance = 0;
   for (; *lhs && *rhs; lhs++, rhs++) {
      if (*lhs != *rhs)
         distance++;
   }
   return (*lhs || *rhs) ? -1 : distance;
}
```

For more information, check the [Increment pointers approach][approach-increment-pointers].

[approach-increment-pointers]: https://exercism.org/tracks/c/exercises/hamming/approaches/increment-pointers
