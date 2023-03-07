# Introduction

There are many ways to solve Pangram.
One approach is to use a bit field to keep track of used letters.

## General guidance

The key to solving Pangram is determining if all of the letters in the English alphabet are in the string being tested.
The occurrence of either the letter `a` or the letter `A` would count as the same letter.

## Approach: Bit field

**pangram.h**
```c
#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

bool is_pangram(const char *sentence);

#endif
```

**pangram.c**
```c
#include "pangram.h" 

bool is_pangram(const char *sentence)
{
    if (!sentence)
        return false;
    int phrasemask = 0;
    char letter;
    
   while ((letter = *sentence) != '\0') {
      // a-z
      if (letter >= 'a' && letter <= 'z')
         phrasemask |= 1 << (letter - 'a');
      // A - Z
      else if (letter >= 'A' && letter <= 'Z')
         phrasemask |= 1 << (letter - 'A');
      sentence++;
   }
     return phrasemask == 67108863;
}
```

For more information, check the [Bit field approach][approach-bitfield].

[approach-bitfield]: https://exercism.org/tracks/c/exercises/pangram/approaches/bitfield
