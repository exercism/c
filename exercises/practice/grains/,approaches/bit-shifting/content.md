# Bit-shifting

**grains.h**

```c
#ifndef GRAINS_H
#define GRAINS_H

#include <stdint.h>

uint64_t square(uint8_t index);
uint64_t total(void);

#endif
```

**grains.c**

```c
#include "grains.h"

uint64_t square(uint8_t index)
{
    return (index > 0 && index < 65) ? 1ul << (index - 1) : 0;
}

uint64_t total(void)
{
    return ((((uint64_t)1 << 63) - 1) << 1) + 1;
}
```

Instead of using math to calculate the number of grains on a square, you can set a bit in the correct position of a `uint64_t`.

To understand how this works, consider just two squares that are represented in binary bits as `00`.

You use the [left-shift operator][left-shift-operator] (`<<`) to set `1` at the position needed to make the correct decimal value.

- To set the one grain on Square One you shift `1` for `0` positions to the left.
So, if `index` is `1` for square One, you subtract `index` by `1` to get `0`, which will not move it any positions to the left.
The result is binary `01`, which is decimal `1`.
- To set the two grains on Square Two you shift `1` for `1` position to the left.
So, if `index` is `2` for square Two, you subtract `index` by `1` to get `1`, which will move it `1` position to the left.
The result is binary `10`, which is decimal `2`.

| Square  | Shift Left By | Binary Value | Decimal Value |
| ------- | ------------- | ------------ | ------------- |
|       1 |             0 |         0001 |             1 |
|       2 |             1 |         0010 |             2 |
|       3 |             2 |         0100 |             4 |
|       4 |             3 |         1000 |             8 |

For `total` we want all of the 64 bits set to `1` to get the sum of grains on all sixty-four squares.
The easy way to do this is to set the 65th bit to `1` and then subtract `1`.
However, we can't do this with a `uint64_t` which has only `64` bits.
Using a four squares example, if the number were only four bits long, we can't set the fifth bit.

- We _can_ shift `1` left three times to get `1000` binary.
- We can then subtract `1` from it to get a number of all `1`s except for the leftmost bit (`0111`).
- We can then shift that number once to the left to get all `1`s except for the righttmost bit `1110`.
- Finally, we can add `1` to that number to get all `1`s (`1111`).

The same can be done with `64` squares by shifting `1` left `63` times.

- We can then subtract `1` from it to get a number of all `1`s except for the leftmost bit.
- We can then shift that number once to the left to get all `1`s except for the righttmost bit.
- Finally, we can add `1` to that number to get all `1`s.

## Optimization

```c
#include "grains.h"
#include <limits.h>

uint64_t total(void)
{
    return UINT64_MAX;
}
```

The `UINT64_MAX` value from the [limits.h][limits-h] file is the value of having all `64` bits in a `uint64_t` set to `1`.
That is the value needed to represent the doubling of grains from the first square through the 64th square.

For example, four squares would be represented by `1111` which is `0001` + `0010` + `0100` + `1000` in binary,
or `1` + `2` + `4` + `8` in decimal.
Binary `1111` is `15` in decimal, which would be the maximum value of a four-bit unsigned integer (`0` through `15`).

[left-shift-operator]: https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
[limits-h]: https://www.tutorialspoint.com/c_standard_library/limits_h.htm
