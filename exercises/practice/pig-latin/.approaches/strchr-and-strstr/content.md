# `strchr` and `ststr`

**pig_latin.h**

```c
#ifndef PIG_LATIN_H
#define PIG_LATIN_H

char *translate(const char *phrase);

#endif
```

**pig_latin.c**

```c
#include "pig_latin.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUFFIX_LEN 8
#define MAX_PHRASE_LEN 32
static const char DELIMITERS[] = " ";
static const char *VOWELS = "aeiou";
static const char *VOWELS_Y = "aeiouy";

static bool process_vowel_start(const char *word, char *output)
{
   if (strchr(VOWELS, *word) != NULL || strstr(word, "xr") == word ||
       strstr(word, "yt") == word) {
      strncat(output, word, MAX_PHRASE_LEN);
      strncat(output, "ay", MAX_PHRASE_LEN);
      return true;
   }
   return false;
}

static void process_vowel_y(const char *word, char *output)
{
   char pig_suffix[MAX_SUFFIX_LEN];
   strncat(pig_suffix, word, 1);
   for (const char *cur_word = word + 1; *cur_word; cur_word++) {
      if (strchr(VOWELS_Y, *cur_word) != NULL) {
         if (*cur_word == 'u') {
            if (*--cur_word == 'q') {
               strncat(pig_suffix, ++cur_word, 1);
            }
            ++cur_word;
         }
         strncat(output, cur_word, MAX_PHRASE_LEN);
         strncat(output, pig_suffix, MAX_PHRASE_LEN);
         strncat(output, "ay", MAX_PHRASE_LEN);
         return;
      }
      strncat(pig_suffix, cur_word, 1);
   }
   strncat(output, pig_suffix, MAX_PHRASE_LEN);
}

char *translate(const char *phrase)
{
   char *output = calloc(MAX_PHRASE_LEN + 1, 1);
   char input[MAX_PHRASE_LEN + 1];
   strncpy(input, phrase, MAX_PHRASE_LEN);
   char *word = strtok(input, DELIMITERS);
   bool starting = true;
   do {
      if (!starting)
         strcat(output, " ");
      if (process_vowel_start(word, output))
         continue;
      process_vowel_y(word, output);
      starting = false;
   } while ((word = strtok(NULL, DELIMITERS)));
   return output;
}
```

This approach starts by defining the maximum expected length of the beginning part of the word that will be moved to the end of the word.
It then defines the maximum expected length of the input into the `translate` function, based on the test input.

A space is defined as the delimiter between words.
Then vowels are defined both without and with a `y`.

The `process_vowel_start` function takes pointers to the `word` string and the `output` string .
The [`strchr`][strchr] functon is used to check if the first character of the `word` is in the `VOWELS` string.
Dereferencing `word` (`*word`) will return the `char` currently being pointed to, which in this case is expected to be the first character.
If the return from `strchr` is not `NULL`, then the logical OR (`||`) [short-circuits][short-circuit] as `true`, and the word and `ay` are concatenated
to the `output` string.

The [`strncat`][strncat] function is used to concatenate to the `output`.
When the input to the `translate` function is only one word (which is all but one test), it will ensure the `output` is not longer than the maximum phrase length.

If the `word` does not start with a vowel, then the [`strstr`][strstr] function is used to check if the `word` starts with `xr` or `yt`.
If it starts with either, then the `word` and `ay` will be concatenated to the `output` string.

If the `word` was concatenated to the `output` string, then the function returns `true`, otherwise it returns `false`.

The `process_vowel_y` function starts be defining the TODO

[strchr]: https://cplusplus.com/reference/cstring/strchr/
[strstr]: https://cplusplus.com/reference/cstring/strstr/
[short-cicruit]: https://www.geeksforgeeks.org/short-circuit-evaluation-in-programming/
[strncat]: https://cplusplus.com/reference/cstring/strncat/
