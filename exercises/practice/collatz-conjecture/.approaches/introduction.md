# Introduction

There are several ways to solve Collatz Conjecture.
One approach can use bitwise operations to check for an even number and divide.

## Approach: Use bitwise operations

**collatz_conjecture.h**

```c
#ifndef COLLATZ_CONJECTURE_H
#define COLLATZ_CONJECTURE_H

#define ERROR_VALUE -1

int steps(int start);

#endif
```

**collatz_conjecture.c**

```c
#include "collatz_conjecture.h"

int steps(int start)
{
   if (start < 1)
      return ERROR_VALUE;
   int step_count = 0;
   while (start != 1) {
      if (!(start & 1))
         start = start >> 1;
      else
         start = (start * 3) + 1;
      step_count++;
   }
   return step_count;
}
```

For more information, check the [Bitwise operations approach][approach-bitwise-operations].

[approach-bitwise-operations]: https://exercism.org/tracks/c/exercises/collatz-conjecture/approaches/bitwise-operations
