# Increment pointers

**hamming.h**

```c
#ifndef HAMMING_H
#define HAMMING_H

int compute(const char *lhs, const char *rhs);

#endif
```

**hamming.c**

```c
#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
   if (!lhs || !rhs)
      return -1;

   int distance = 0;
   for (; *lhs && *rhs; lhs++, rhs++) {
      if (*lhs != *rhs)
         distance++;
   }
   return (*lhs || *rhs) ? -1 : distance;
}
```

This approach starts by checking if either the `lhs` or `rhs` strings are `NULL`.
If so, then the function returns `-1`.

~~~~exercism/note
There is a difference between a `NULL` pointer and a valid pointer pointing to a null character (`'\0'`).
~~~~

The variable to keep track of the distance count is initialized to `0`.

The `for` loop begins with no initialization statement.
The reason the `distance` variable is not initialized in the `for` loop is because its scope would be confined to the loop and
it would be destroyed at the end of the loop.
Since the pointers are being incremented directly, there is no counter variable needed to be defined and incremented.

The conditional statement will iterate the loop as long as both pointers are not pointing to a null character (`'\0'`).
The loop increments both the `lhs` and `rhs` pointers.

Inside the loop, the characters at the dereferenced pointers are compared.
The `distance` variable is incremented for each time the characters at the same position in the two strings do not match.

The loop will stop when one or more of the pointers is pointing at a null character.

A [ternary operator][ternary] is used to check if either of the pointers is not pointing to a null character.
If so, the strings are not the same length, and `-1` is returned.
Otherwise, the value of the `distance` variable is returned.

[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
