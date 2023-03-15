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

This approach starts by defining the maximum expected length of the beginning part of the word that will be moved to the end of the word.
It then defines the maximum expected length of the input string into the `translate` function, based on the test input.

A space is defined as the delimiter between words.
Then vowels are defined both without and with a `y`.

```c
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
```

The `process_vowel_start` function takes pointers to the `word` string and the `output` string .
The [`strchr`][strchr] functon is used to check if the first character of the `word` is in the `VOWELS` string.
Dereferencing `word` (`*word`) will return the `char` currently being pointed to, which in this case is expected to be the first character.
If the return from `strchr` is not `NULL`, then the logical OR (`||`) [short-circuits][short-circuit] as `true`, and the word and `ay` are concatenated
to the `output` string.

The [`strncat`][strncat] function is used to concatenate to the `output`.
When the input to the `translate` function is only one word (which happens in all but one of the tests),
it will ensure the `output` is not longer than the maximum phrase length.

If the `word` does not start with a vowel, then the [`strstr`][strstr] function is used to check if the `word` starts with `xr` or `yt`.
If it starts with either, then the `word` and `ay` will be concatenated to the `output` string.

If the `word` was concatenated to the `output` string, then the function returns `true`, otherwise it returns `false`.

The `process_vowel_y` function takes pointers to the `word` string and the `output` string .
A `char` array for the word suffix is defined, and the first character is initialized as a null character,
making it an empty string.
The first character of `word` is concatenated to the suffix.

The `for` loop creates another pointer to the `word` and it initializes it to point to the second character (`word + 1`).
The loop will iterate as long as the `cur_word` is pointing to a non-`NULL` character.

```c
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
```

The `strchr` function is used to check if the `char` currently pointed at is in the `VOWELS_Y` string.
If so, and the current `char` is a `u`, then the pointer is decremented to see if the previous character is a `q`.
If the previous `char` was a `q`, then the pointer is incremented back to point to `u`, and the `u` is concatenated to the suffix.
If the word was `quick`, then the pointer is desired to be at the `i` (one past `q`).
If the word was `bug`, then the pointer is desired to be at the `u`.
Testing for `q` in `bug` moved the pointer to `b`, and since it was not preceeded by `q` it was not incremented back to `u`.
So, for both situations, the pointer is incremented again.

Concatenation for any vowel is the same.
The word from the `char` curently pointed at until the end of the word is concatenated to the `output` string.
Then the first part of the word (now in the suffix string), is concatenated to the `output` string.
Finally, `ay` is concatenated to the `output` string, and the function returns.

If the current `char` is not a vowel, then it is concatenated to the suffix and the pointer is incremented.

After the loop is done, if no vowel was found, the the suffix, which would now be the whole `word`, is concatenated to the `output` string as is.

The `translate` function takes a pointer to the `input` phrase.

```exercism/note
For production, the pointer should be checked for `NULL` and that the string is not longer than the `MAX_PHRASE_LEN`, but those and other checks
are not made in this approach to keep the implementation simple.
```

The [`calloc`][calloc] function is used to allocate memory for the `output` string.

The [`strncpy`][strncpy] function is used to copy the input phrase into a `char` array that can be iterated with the [`strtok`][strtok`] function.
The `strtok` function take a `char *` input string (not a `const char *` string ) and a string of delimiters to split the input string by the delimiters.

```c
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
```

Inside the `do` loop, if the loop is not starting, then a space is concatenated to the `output` string with the [`strcat`][strcat] function.

```exercism/note
For a discussion of why `strcat` is used here instead of `strncat`, see this
[StackOverflow thread](https://stackoverflow.com/questions/53408543/strncat-wformat-overflow-warning-when-using-gcc-8-2-1).
```

If the call to the `process_vowel_start` function returns `true`, then the word starts wioth a vowel (or `xr` or `yt`) and `continue` is used
to go to the `while` check of the loop.

If `process_vowel_start` returns false, then `process_vowel_y` is called.

The `while` check uses an assignment expression that assigns the `word` variable to the result of calling `strtok`.
If `word` is not a `NULL` pointer then the loop will iterate again, otherwise the loop will exit.

When the loop is done, the function returns the `output` string.

[strchr]: https://cplusplus.com/reference/cstring/strchr/
[strstr]: https://cplusplus.com/reference/cstring/strstr/
[short-circuit]: https://www.geeksforgeeks.org/short-circuit-evaluation-in-programming/
[strncat]: https://cplusplus.com/reference/cstring/strncat/
[calloc]: https://cplusplus.com/reference/cstdlib/calloc/
[strncpy]: https://cplusplus.com/reference/cstring/strncpy/
[strtok]: https://cplusplus.com/reference/cstring/strtok/
[strcat]: https://cplusplus.com/reference/cstring/strcat/
