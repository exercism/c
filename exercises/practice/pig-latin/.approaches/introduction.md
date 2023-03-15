# Introduction

There are various ways to solve Pig Latin.
One approach can use the [`strchr`][strchr] and [`strstr`][strstr] functions to look for vowels.

## General guidance

At the time of writing only four rules need to be handled, but when they have similar output, they don't need to be handled completely separately.
Handling each rule independently might lead to longer code than is needed.

## Approach: `strchr` and `ststr`

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
   char pig_suffix[MAX_SUFFIX_LEN] = { 0 };
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

For more information, check the [`strchr` and `strstr` approach][approach-strchr-and-strstr].

[approach-strchr-and-strstr]: https://exercism.org/tracks/c/exercises/pig-latin/approaches/strchr-and-strstr
[strchr]: https://cplusplus.com/reference/cstring/strchr/
[strstr]: https://cplusplus.com/reference/cstring/strstr/
