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
    const char *pos = sentence;
    char letter;
    
    while ((letter = *pos) != '\0')
    {
        // a-z
        if (letter > 96 && letter < 123)
            phrasemask |= 1 << (letter - 97);
        // A - Z
        else if (letter > 64 && letter < 91)
            phrasemask |= 1 << (letter - 65);
        pos++;
    }
     return phrasemask == 67108863;
}
```

For more information, check the [Bit field approach][approach-bitfield].

[approach-bitfield]: https://exercism.org/tracks/c/exercises/pangram/approaches/bitfield
