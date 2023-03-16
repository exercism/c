# Introduction

There are many ways to solve Scrabble Score.
A straightforward and performant approach is to look up the scores with a `switch`.
Another approach could look up the scores from an array.

## Approach: `switch` statement

**scrabble_score.h**

```c
#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

unsigned int score(const char *word);

#endif
```

**scrabble_score.c**

```c
#include "scrabble_score.h"
#include <ctype.h>
#include <stddef.h>

static unsigned int letter_score(char letter)
{
   switch (tolower(letter)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'l':
      case 'n':
      case 'r':
      case 's':
      case 't':
         return 1;
      case 'd':
      case 'g':
         return 2;
      case 'b':
      case 'c':
      case 'm':
      case 'p':
         return 3;
      case 'f':
      case 'h':
      case 'v':
      case 'w':
      case 'y':
         return 4;
      case 'k':
         return 5;
      case 'j':
      case 'x':
         return 8;
      case 'q':
      case 'z':
         return 10;
   }
   return 0;
}
unsigned int score(const char *word)
{
   if (word == NULL)
      return 0;
   unsigned int total_score = 0;
   for (; *word; ++word)
      total_score += letter_score(*word);
   return total_score;
}
```

For more information, check the [`switch` statement approach][approach-switch-statement].

## Approach: Array lookup

**scrabble_score.h**

```c
#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

unsigned int score(const char *word);

#endif
```

**scrabble_score.c**

```c
#include "scrabble_score.h"
#include <ctype.h>
#include <stddef.h>

typedef struct score_pair {
   unsigned int score;
   char *letters;
} score_pair;

static const score_pair compressed_scores[] = {
   { 1, "aeioulnrst" }, { 2, "dg" }, { 3, "bcmp" }, { 4, "fhvwy" },
   { 5, "k" },          { 8, "jx" }, { 10, "qz" }
};

static unsigned int scores[26] = { 0 };
static int scoresInitialized = 0;

static void initialize_scores()
{
   if (scoresInitialized)
      return;
   for (int compressedPos = 0; compressedPos < 7; compressedPos++) {
      score_pair pair = compressed_scores[compressedPos];
      char *ltrs = pair.letters;
      for (; *ltrs; ltrs++) {
         scores[*ltrs - 'a'] = pair.score;
      }
   }
   scoresInitialized = 1;
}

unsigned int score(const char *word)
{
   if (word == NULL)
      return 0;
   initialize_scores();
   unsigned int total_score = 0;
   for (; *word; word++)
      total_score += scores[tolower(*word) - 'a'];
   return total_score;
}
```

For more information, check the [Array lookup approach][approach-array-lookup].

[approach-switch-statement]: https://exercism.org/tracks/c/exercises/scrabble-score/approaches/switch-statement
[approach-array-lookup]: https://exercism.org/tracks/c/exercises/scrabble-score/approaches/array-lookup
