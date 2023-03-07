# Bit field

**pangram.h**
```c
#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

bool is_pangram(const char *sentence);

#endif
```

**pangram.c**
```c
#include "pangram.h" 

bool is_pangram(const char *sentence)
{
    if (!sentence)
        return false;
    int phrasemask = 0;
    const char *pos = sentence;
    char letter;
    
    while ((letter = *pos) != '\0')
    {
        // a-z
        if (letter > 96 && letter < 123)
            phrasemask |= 1 << (letter - 97);
        // A - Z
        else if (letter > 64 && letter < 91)
            phrasemask |= 1 << (letter - 65);
        pos++;
    }
     return phrasemask == 67108863;
}
```

The `is_pangram` function starts by using the logical NOT operator (`!`) to check if the pointer to the input is NULL.
There is a difference between a NULL pointer and a valid pointer pointing to a null character (`'\0'`).

An `int` is defined to keep track of the used letters of the English alphabet.
Since only the rightmost 26 bits will be used, there is no need to have unsignedness.

A pointer is defined to point at the same address as the input sentence pointer.
It points at `const char` to indicate that it will not be modifying the `char`s pointed at.
It isn't strictly necessary to define a separate variable.
`C` arguments are passed by value, meaning that the actual pointer to the input sentence is not passed in, but a copy of the address it's pointing to.
So the `sentence` address passed in could be incremented directly.
A reason to use a separate pointer would be if you wanted to refer to the beginning of the input sentence variable again in the body of the function.
You won't do that here, but if you wanted to refactor to do that in the future, it would make doing so a bit easier by having incremented a separate pointer.

A `char` is defined for each character to be tested in the loop.

The `while` loop uses an assignment expression for its condition.
The expression `(letter = *pos)` has the value of `letter` after it has been been assigned the value of the dereferenced `pos` pointer.
If the value of `letter` is a null character (`'\0'`), then the while loop will not run.
Note that, had the `sentence` pointer not been checked for being NULL, then trying to dereference `*pos` if it were a NULL pointer would be undefined behavior.
It likely would result in a segmentation fault.


The [ASCII][ascii] value of the `letter` is compared with a range of ASCII values to check if it is one of the lowercase English letters.
- The ASCII value for `a` is `97`, and for `z` is `122`.
- If the lowercase letter is subtracted by `97`, then `a` will result in `0`, because `97` minus `97` equals `0`.
  `z` would result in `25`, because `122` minus `97` equals `25`.
  So `a` would have `1` [shifted left][shift-left] 0 places (so not shifted at all) and `z` would have `1` shifted left 25 places.
- The [bitwise OR operator][bitwise-or] is used to set the bit at that position in the `phrasemask`.

If the `letter` is not a lowercase English letter,
the ASCII value of the `letter` is compared with a range of ASCII values to check if it is one of the uppercase English letters.
- The ASCII value for `A` is `65`, and for `Z` is `90`.
- If the uppercase letter is subtracted by `65`, then `A` will result in `0`, because `65` minus `65` equals `0`.
  `Z` would result in `25`, because `90` minus `65` equals `25`.
  So `A` would have `1` [shifted left][shift-left] 0 places (so not shifted at all) and `Z` would have `1` shifted left 25 places
- The [bitwise OR operator][bitwise-or] is used to set the bit at that position in the `phrasemask`.

So, for a 32-bit integer, if the values for `a` and `Z` were both set, the bits would look like

```
      zyxwvutsrqponmlkjihgfedcba
00000010000000000000000000000001
```

After the loop completes, the function returns if the `phrasemask` value is the same value as when all `26` bits are set.
The value for all `26` bits being set is `67108863`.

[ascii]: https://www.asciitable.com/
[shift-left]: https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
[bitwise-or]: https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
