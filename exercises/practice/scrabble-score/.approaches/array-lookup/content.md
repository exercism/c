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

This approach starts by defining a struct which holds a score and a string of letters.
An array of that struct type is defined, with each element being that struct with a score and a string of its related letters.

Next is defined an array to hold the score for each of the `26` letters of the English alphabet.
A variable is defined with a value of `false` to indicate if the `score` array has been initialized yet.

The `initialize_scores` function first checks if `scoresInitialized` is `true`.
If so, it immediately returns.
Otherwise, it sets up a `for` loop to iterate the array of structs.

Inside the outer `for` loop, an inner `for` loop is set up to iterate the string of letters for the current struct.
The conditional statement will iterate the inner loop as long as the `ltrs` pointer is not pointing to a null character (`'\0'`).
The inner loop increments the `ltrs` pointer.
Since the `ltrs` pointer is being incremented directly, there is no counter variable needed to be defined and incremented.

Inside the inner `for` loop, the element in the `score` array for that letter has its score set from `score` field of the current struct.
The corresponding elements of the `score` array relate to the position of the letter in the English alphabet.
So `a` is at index `0`, `b` is at index `1`, up through `z` which is at index `25`.
Subtracting the current `char` by `a` subtracts the [`ASCII`][ascii] value of the current `char` by the ASCII value of `a`.

- For example, `a` subtracted by `a` would be `97` minus `97` for `0`.
- `b` subtracted by `a` would be `98` minus `97` for `1`.
- `z` subtracted by `a` would be `122` minus `97` for `25`.

After the loops are done, the `scoresInitialized` variable is set to `1`.

The `score` function takes a pointer to the `word` being scored.
It checks if the pointer is `NULL`.
If so, then the function returns `0`.

```exercism/note
There is a difference between a `NULL` pointer and a valid pointer pointing to a null character (`'\0'`).
```

The `initialize_scores` function is called.
If the `scores`  array has already been initialized, the function will return immediately.

The variable to keep track of the accumulated score is initialized to `0`.

The `for` loop begins with no initialization statement.
The reason the `total_score` variable is not initialized in the `for` loop is because its scope would be confined to the loop and
it would be destroyed at the end of the loop.

The conditional statement will iterate the loop as long as the `word` pointer is not pointing to a null character (`'\0'`).
The loop increments the `word` pointer.
Since the `word` pointer is being incremented directly, there is no counter variable needed to be defined and incremented.

Inside the loop, the [`tolower`][tolower] function is used on the character at the dereferenced pointer before subtracting it by `a`
as the index into the `scores` array.
The `total_score` variable is added to from the result of getting the value from the `score` array at that index.

The loop will stop when the `word` pointer is pointing at a null character.

The value of the `total_score` variable is returned.

[ascii]: https://www.asciitable.com/
[tolower]: https://www.geeksforgeeks.org/tolower-function-in-c/
