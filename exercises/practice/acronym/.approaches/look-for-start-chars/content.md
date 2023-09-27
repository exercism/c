# Look for start chars

**acronym.h**

```c
#ifndef ACRONYM_H
#define ACRONYM_H

char *abbreviate(const char *phrase);

#endif
```

**acronym.c**

```c
#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase)
{
   if (!phrase || !(*phrase))
      return NULL;

   char *acronyms = malloc(strlen(phrase) + 1);
   if (!acronyms)
      return NULL;
   char *acronyms_start = acronyms;

   const char start_trigger[] = " -";
   for (int start = 1; *phrase; phrase++) {
      if (start && isalpha(*phrase)) {
         *acronyms++ = toupper(*phrase);
         start = 0;
      } else if (strchr(start_trigger, *phrase))
         start = 1;
   }
   *acronyms = '\0';
   return acronyms_start;
}
```

This `abbreviate` function starts by checking for the input pointer being `NULL` or an empty string.

~~~~exercism/note
There is a difference between a `NULL` pointer and a valid pointer pointing to a null character (`'\0'`).
~~~~

If the pointer is either `NULL` or en empty string, the function returns `NULL`.

The [`strlen`][strlen] function is used to define the size of the output string allocated by the [`malloc`][malloc] function.
Note the `strlen` function does not include the terminating `'\0'` for the length, so `1` is added to the result of `strlen` for the `malloc` size.
For example, if the input phrase is only one character, the result of `strlen` is `1`.
But trying to write the one character plus the terminating `'\0'` would result in overflow if the output string was allocated for only `1` byte.

If allocating the memory for the output string fails, `malloc` returns `NULL`, which would be returned by the function.
Otherwise, a pointer is defined to keep the place at the beginning of the output string.

Based on the test input, a `char` array is defined that holds the characters that signal an upcoming beginning of a word.
At the time of writing, those characters are a space or a hyphen.

The `for` loop initializes a `start` flag variable to `1`.
The `for` loop will iterate as long as the dereferenced phrase pointer is not a terminating null character (`'\0'`).
The loop increments the phrase pointer after each iteration.

If the `start` flag is `true` (i.e., not zero), then the [`isalpha`][isalpha] function is used to check if the current `char` is an alphabetic character.
This check is made because the `start` flag could be `true`, but the current `char` could be another start trigger, or it could be an underscore.
If the current `char` is alphabetic,
then the [`isupper`][isupper] function is used to set the value at the current position of the acronyms pointer to the upppercased `char`.
The acronyms pointer is then incremented, and the `start` flag is set to `0`.

If either the `start` flag is not `true`, or the current `char` is not alphabetic,
then the [`strchr`][strchr] function is used to check if the current `char` is one of the start trigger characters.
If so, then the `start` flag is set to `1`.

After the `for` loop is done, the terminating null character (`'\0'`) is set at the current position of the acronyms pointer.
The function then returns the pointer to the beginning of the acronyms string.

[strlen]: https://www.geeksforgeeks.org/strlen-function-in-c/
[malloc]: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
[isalpha]: https://www.geeksforgeeks.org/isalpha-isdigit-functions-c-example/
[isupper]: https://www.geeksforgeeks.org/isupper-function-c-language/
[strchr]: https://cplusplus.com/reference/cstring/strchr/
