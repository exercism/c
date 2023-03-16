# Array lookup

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

TODO
