# Introduction

There are many ways to solve Beer Song.
Some approaches try to minimize hardcoded duplication by fragmenting the data into the smallest pieces and using
a certain amoount of complexity in the code to cobble the pieces of data together.
Another approach can try to put the complexity in the data to make the code as simple as possible.

# Approach: Complexity in Data

**beer_song.h**

```c
#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <stdint.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song);

#endif
```

**beer_song.c**

```c
#include "beer_song.h"
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)

static const char *FIRST_LINE[] = {
   "No more bottles of beer on the wall, no more bottles of beer.",
   "1 bottle of beer on the wall, 1 bottle of beer.",
   "%u bottles of beer on the wall, %u bottles of beer."
};

static const char *SECOND_LINE[] = {
   "Go to the store and buy some more, 99 bottles of beer on the wall.",
   "Take it down and pass it around, no more bottles of beer on the wall.",
   "Take one down and pass it around, 1 bottle of beer on the wall.",
   "Take one down and pass it around, %u bottles of beer on the wall."
};

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
   uint8_t end_bottle = start_bottles - (take_down - 1);
   for (int bottle = start_bottles; bottle >= end_bottle; bottle--) {
      snprintf(*song++, MAX_LINE_LENGTH, FIRST_LINE[bottle > 1 ? 2 : bottle],
               bottle, bottle);
      snprintf(*song++, MAX_LINE_LENGTH,
               SECOND_LINE[bottle - 1 > 2 ? 3 : bottle], bottle - 1);
      song++;
   }
}
```

For more information, check the [Complexity in Data approach][approach-complexity-in-data].

[approach-complexity-in-data]: https://exercism.org/tracks/c/exercises/beer-song/approaches/complexity-in-data
