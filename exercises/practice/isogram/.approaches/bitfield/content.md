# Bit field

**isogram.h**

```c
#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>

bool is_isogram(const char phrase[]);

#endif
```

**isogram.c**

```c
#include "isogram.h"
#include <stdint.h>

bool is_isogram(const char phrase[])
{
   if (!phrase)
      return false;

   uint32_t letter_flags = 0;
   char sub = 'a';

   while (*phrase) {
      char letter = *phrase;
      if (letter >= 'a' && letter <= 'z')
         sub = 'a';
      else if (letter >= 'A' && letter <= 'Z')
         sub = 'A';
      else
         sub = 'X';

      if (sub != 'X') {
         if ((letter_flags & (1 << (letter - sub))) != 0)
            return false;
         else
            letter_flags |= (1 << (letter - sub));
      }
      phrase++;
   }
   return true;
}
```

This approach uses the [ASCII][ascii] value of the letter to set the corresponding bit position.

The approach starts by checking if the pointer to the input phrase is `NULL`.
If so, then the function returns `false`.

```exercism/note
There is a difference between a `NULL` pointer and a valid pointer pointing to a null character (`'\0'`).
```

The `uint32_t` value for the bit field is initialized with `0`.
A character to subtract by is initialized to `'a'`.

The input  `phrase` is looped through its characters, looking for a character being `a` through `z` or `A` through `Z`.

- The ASCII value for `a` is `97`, and for `z` is `122`.
- The ASCII value for `A` is `65`, and for `Z` is `90`.

The character to be subtracted by is set according to whether the character is a lowercase letter, uppercase letter, or something else.
If a character is neither an uppercase or lowercase letter, it is ignored.
Otherwise, the ASCII value of the letter is used to calculate its position in the bit field.

- If a lowercase letter is subtracted by `a`, then `a` will result in `0`, because `97` minus `97`  equals `0`.
`z` would result in `25`, because `122` minus `97` equals `25`.
So `a` would have `1` [shifted left][bitwise-operators] 0 places (so not shifted at all) and `z` would have `1` shifted left 25 places.
- If an uppercase letter is subtracted by `A`, then `A` will result in `0`, because `65` minus `65`  equals `0`.
`Z` would result in `25`, because `90` minus `65` equals `25`.
So `A` would have `1` shifted left 0 places (so not shifted at all) and `Z` would have `1` shifted left 25 places.

In that way, both a lowercase `z` and an uppercase `Z` can share the same position in the bit field.

So, for an unsigned thirty-two bit integer, if the values for `a` and `Z` were both set, the bits would look like

```
      zyxwvutsrqponmlkjihgfedcba
00000010000000000000000000000001
```

The bitwise AND operator can be used to check if a bit has already been set.
If it has been set, the letter is duplicated and `false` can be returned immediately.
If it has not been set, then the bitwise OR operator can be used to set the bit.
If the loop completes without finding a duplicate letter (and returning `false`), the function returns `true`.

[ascii]: https://www.asciitable.com/
[bitwise-operators]: https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
