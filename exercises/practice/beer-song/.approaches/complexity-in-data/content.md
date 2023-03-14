# Complexity in Data

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
   for (int8_t bottle = start_bottles; bottle >= end_bottle; bottle--) {
      snprintf(*song++, MAX_LINE_LENGTH, FIRST_LINE[bottle > 1 ? 2 : bottle],
               bottle, bottle);
      snprintf(*song++, MAX_LINE_LENGTH,
               SECOND_LINE[bottle - 1 > 1 ? 3 : bottle], bottle - 1);
      song++;
   }
}
```

In [this video][video] by the creator of Exercism, she explains that every solution she had seen of Beer Song was horribly complex until she asked a friend to solve it.
The friend came up with four solutions, one of which in particular seemed to strip away the complexity.

Linus Torvalds, the creator of Linux, is quoted saying:

>Bad programmers worry about the code. Good programmers worry about data structures and their relationships.

The same idea is formulated in _The Art of Unix Programming_ by Eric S. Raymond as the "Rule of Representation":

>Fold knowledge into data so program logic can be stupid and robust.

>Data is more tractable than program logic. It follows that where you see a choice between complexity in data structures and complexity in code, choose the former.
More: in evolving a design, you should actively seek ways to shift complexity from code to data.

This approach minimizes complexity in code by allowing for a bit more duplicate hardcoding than other approaches which disallow any duplication in the data at all.

The maximum length for a line is defined with the value taken from the test file.

Arrays are defined to hold the varying values for the first and second lines of each verse.
The last element of each array is a template for the verses that have the same wording and only change the bottle number.

The `recite` function accepts two arguments of `uint8_t` and a buffer for writing the output.
Since 8-bit unsigned integers can hold values from `0` through `255`, so they are big enough to hold the values of bottles from `0` through `99`.

The `end_bottle` is defined in a way so that it will not be `-1`.
If the `start_bottles` is `1` and the `take_down` is `2`, the `end_bottle` is defined as `0` so it can be a `uint8_t`.
This constrains the numbers for the bottles to be valid positive numbers.

Accordingly, the `for` loop iterates from the `start_bottles` while the `bottle` number is greater than or equal to the `end_bottle`.

Inside the `for` loop, the [snprintf][snprintf] function uses the `MAX_LINE_LENGTH` value to write each line to the buffer.

```exercism/note
The `snprintf` function is used instead of `sprintf`, because the `sprintf` function can be dangerous,
as it can potentially output more characters than can fit in the allocation size of the buffer.
That is particularly a concern when writing user input to the buffer.
This approach does not do that, but to use `snprintf` instead of `sprintf` is a good habit for secure coding.
```

A [ternary operator][ternary] is used to check if the `bottle` number is greater than `1`.
If so, the element at index `2` of the `FIRST_LINE` array is used as a template,
and the two `bottle` arguments are used in place of the `%u` format specifiers when writing to the buffer.

If the `bottle` number is not greater than `1`, then the element in the `FIRST_LINE` array at the index of the `bottle` number is written
to the buffer, and the two `bottle` arguments are disregarded.

```c
for (int8_t bottle = start_bottles; bottle >= end_bottle; bottle--) {
  snprintf(*song++, MAX_LINE_LENGTH, FIRST_LINE[bottle > 1 ? 2 : bottle],
           bottle, bottle);
  snprintf(*song++, MAX_LINE_LENGTH,
           SECOND_LINE[bottle - 1 > 1 ? 3 : bottle], bottle - 1);
  song++;
}
```

A ternary operator is used to check if the `bottle` number minus `1` is greater than `1`.
If so, the element at index `3` of the `SECOND_LINE` array is used as a template,
and the `bottle - 1` argument is used in place of the `%u` format specifier when writing to the buffer.

If the `bottle - 1` number is not greater than `1`, then the element in the `SECOND_LINE` array at the index of the `bottle` number is written
to the buffer, and the `bottle - 1` argument is disregarded.

The line in the `song` buffer is incremented and the `bottle` number is decremented.
If the `bottle` number is greater than or equal to the `end_bottle`, the `for` loop runs again, otherwise it exits.

## Examples:

```c
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
```

For `bottle` number `3`, it is greater than `1`, so the template is used to write the first line like so

```
"3 bottles of beer on the wall, 3 bottles of beer."
```

And `3` minus `1` is greater than `1`, so the template is used to write the second line like so

```
"Take one down and pass it around, 2 bottles of beer on the wall."
```

For `bottle` number `2`, it is greater than `1`, so the template is used to write the first line like so

```
"2 bottles of beer on the wall, 2 bottles of beer."
```

`2` minus `1` is not greater than `1`, so the element in `SECOND_LINE` at index `2` is used to write the second line like so

```
"Take one down and pass it around, 1 bottle of beer on the wall."
```

For `bottle` number `1`, it is not greater than `1`, so the element in `FIRST_LINE` at index `1` is used to write the first line like so

```
"1 bottle of beer on the wall, 1 bottle of beer."
```

`1` minus `1` is not greater than `1`, so the element in `SECOND_LINE` at index `1` is used to write the second line like so

```
"Take it down and pass it around, no more bottles of beer on the wall."
```

For `bottle` number `0`, it is not greater than `1`, so the element in `FIRST_LINE` at index `0` is used to write the first line like so

```
"No more bottles of beer on the wall, no more bottles of beer."
```

`0` minus `1` is not greater than `1`, so the element in `SECOND_LINE` at index `0` is used to write the second line like so

```
"Go to the store and buy some more, 99 bottles of beer on the wall."
```

[video]: https://www.youtube.com/watch?v=Q1Tlo4VnQrA
[snprintf]: https://cplusplus.com/reference/cstdio/snprintf/
[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
