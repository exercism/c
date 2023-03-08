#Introduction

# Introduction

There are several variants of a general approach for solving Sieve.
A general approach is to keep track of composite numbers with an array of `0/1` values.

## Approach: Array of ones and zeros

**sieve.h**

```c
#ifndef SIEVE_H
#define SIEVE_H

#include <stdint.h>
#include <stddef.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes);

#endif
```

**sieve.c**

```c
#include "sieve.h"

#define MAX_LEN 1001

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
   if (limit < 2 || max_primes == 0)
      return 0;

   uint32_t composite[MAX_LEN];
   for (int i = 0; i < MAX_LEN; i++)
      composite[i] = 0;

   size_t output_pos = 0;
   for (uint32_t number = 2; number <= limit; number++) {
      if (!composite[number]) {
         primes[output_pos++] = number;
         if (output_pos == max_primes)
            break;
         for (uint32_t idx = number * number; idx <= limit; idx += number)
            composite[idx] = 1;
      }
   }
   return (uint32_t)output_pos;
}
```

For more information, check the [Array of ones and zeros approach][approach-array-of-ones-and-zeros].

[approach-array-of-ones-and-zeros]: https://exercism.org/tracks/c/exercises/sieve/approaches/array-of-ones-and-zeros
