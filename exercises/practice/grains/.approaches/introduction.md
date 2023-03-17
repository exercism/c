# Introduction

There are various idiomatic approaches to solve Grains.
One approach is to use bit-shifting.

## General guidance

The key to solving Grains is to focus on each square having double the amount of grains as the square before it.
This means that the amount of grains grows exponentially.
The first square has one grain, which is `2` to the power of `0`.
The second square has two grains, which is `2` to the power of `1`.
The third square has four grains, which is `2` to the power of `2`.
You can see that the exponent, or power, that `2` is raised by is always one less than the square number.

| Square | Power | Value                   |
| ------ | ----- | ----------------------- |
| 1      | 0     | 2 to the power of 0 = 1 |
| 2      | 1     | 2 to the power of 1 = 2 |
| 3      | 2     | 2 to the power of 2 = 4 |
| 4      | 3     | 2 to the power of 3 = 8 |

## Approach: Bit-shifting

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

For more information, check the [Bit-shifting approach][approach-bit-shifting].

[approach-bit-shifting]: https://exercism.org/tracks/c/exercises/grains/approaches/bit-shifting
