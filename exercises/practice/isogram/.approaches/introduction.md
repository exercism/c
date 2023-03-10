# Introduction

There are various idiomatic ways to solve Isogram.
One approach can use a bit field to keep track of used letters.

## General guidance

The key to solving Isogram is to determine if any of the letters in the `string` being checked are repeated.
A repeated letter means the `string` is not an isogram.
The occurrence of the letter `a` and the letter `A` count as a repeated letter, so `Alpha` would not be an isogram.

## Approach: Bit field

**isogram.h**

```c
#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>

bool is_isogram(const char phrase[]);

#endif
```

**isogram.c**

```c
#include "isogram.h"
#include <stdint.h>

bool is_isogram(const char phrase[])
{
   if (!phrase)
      return false;

   uint32_t letter_flags = 0;
   char sub = 'a';

   while (*phrase) {
      char letter = *phrase;
      if (letter >= 'a' && letter <= 'z')
         sub = 'a';
      else if (letter >= 'A' && letter <= 'Z')
         sub = 'A';
      else
         sub = 'X';

      if (sub != 'X') {
         if ((letter_flags & (1 << (letter - sub))) != 0)
            return false;
         else
            letter_flags |= (1 << (letter - sub));
      }
      phrase++;
   }
   return true;
}
```

For more information, check the [Bit field approach][approach-bitfield].

[approach-bitfield]: https://exercism.org/tracks/c/exercises/isogram/approaches/bitfield
