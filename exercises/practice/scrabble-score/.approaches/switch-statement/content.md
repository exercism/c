# `switch` statement

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

This approach starts by defining a function which takes a `char`.
The [`tolower`][tolower] function is used on the input `char` passed to the [`switch`][switch].

Note that multiple values can be tested without putting a `break` statement between them.
Also note that a `break` statement is not needed after a `return` statement.

The `score` function takes a pointer to the `word` being scored.
It checks if the pointer is `NULL`.
If so, then the function returns `0`.

```exercism/note
There is a difference between a `NULL` pointer and a valid pointer pointing to a null character (`'\0'`).
```

The variable to keep track of the accumulated score is initialized to `0`.

The `for` loop begins with no initialization statement.
The reason the `total_score` variable is not initialized in the `for` loop is because its scope would be confined to the loop and
it would be destroyed at the end of the loop.

The conditional statement will iterate the loop as long as the `word` pointer is not pointing to a null character (`'\0'`).
The loop increments the `word` pointer.
Since the `word` pointer is being incremented directly, there is no counter variable needed to be defined and incremented.

Inside the loop, the character at the dereferenced pointer is sent to the `letter_score` function.
The `total_score` variable is added to from the result of calling the `letter_score` function.

The loop will stop when the `word` pointer is pointing at a null character.

The value of the `total_score` variable is returned.

[tolower]: https://www.geeksforgeeks.org/tolower-function-in-c/
[switch]: https://www.tutorialspoint.com/cprogramming/switch_statement_in_c.htm
