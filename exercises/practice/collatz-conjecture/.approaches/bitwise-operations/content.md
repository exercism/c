# Use bitwise operations

**collatz_conjecture.h**

```c
#ifndef COLLATZ_CONJECTURE_H
#define COLLATZ_CONJECTURE_H

#define ERROR_VALUE -1

int steps(int start);

#endif
```

**collatz_conjecture.c**

```c
#include "collatz_conjecture.h"

int steps(int start)
{
   if (start < 1)
      return ERROR_VALUE;
   int step_count = 0;
   while (start != 1) {
      if (!(start & 1))
         start = start >> 1;
      else
         start = (start * 3) + 1;
      step_count++;
   }
   return step_count;
}
```

This approach starts be defining an `ERROR_VALUE` in the header file instead of using `-1` as a [magic number][magic-number].

The `steps` function starts by checking if the input number is less than `1`.
If so, the function returns the `ERROR_VALUE`.

The counter variable is initialized to `0`.

The `while` loop will iterate while the input number is not equal to `1`.
If the input number is already `1`, the `while` loop will not execute and the function will return `0`.

Inside the `while` loop, the input number is [ANDed][bitwise-operators] with `1`.
The falsiness of `0` is used by the [logical NOT operator][logical-not] (`!`) to determine if the number is even.

- For example, if the number is `4`, which is binary `100`, then `100` is bitwise ANDed (`&`) with `001`.
Since `1` is not the rightmost digit in `100`, the result of the AND is `000`, determining that `4` is an even number.
- if the number is `5`, which is binary `101`, then `101` is ANDed with `001`.
Since `1` is the rightmost digit in `101`, the result of the AND is `001`, determining that `5` is an odd number.

If the number is even, then the number is set to half of itself.
Instead of using division by `2`, all of the bits in the number are shifted right (`>>`) once to halve the number.

- For example, if the number is `4`, which is binary `100`, then the bits in `100` are shifted right once to binary `010`,
which is decimal `2`.
- If the number is `6`, which is binary `110`, then the bits in `110` are shifted right once to binary `011`,
which is decimal `3`.

If the number is odd, then it is set to `3` times itself, plus `1`.

Whether the number is even or odd, the loop increments the counter variable for each iteration.

After the input number is reduced to `1` in the `while`loop, the loop is done and the function returns the value of the counter variable.

[magic-number]: https://en.wikipedia.org/wiki/Magic_number_(programming)
[bitwise-operators]: https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
[logical-not]: https://www.geeksforgeeks.org/logical-not-operator-in-c-with-examples/
