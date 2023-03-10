# Introduction

There are several ways to solve Resistor Color.
One approach is to use the [`#define`][define] directive to set the values needed for both the `enum`  and the array.

# General guidance

One thing to try is to minimize duplication in the code.
For instance, to avoid duplicating the value definitions in both the `enum` and in the array.

## Approach: Define  consecutive values

**resistor_color.h**

```c
#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H
#include <stdint.h>

#define COLORS                                                                 \
   BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum RESISTOR_BAND { COLORS } resistor_band_t;

int color_code(resistor_band_t color);
resistor_band_t *colors();

#endif
```

**resistor_color.c**

```c
#include "resistor_color.h"

static resistor_band_t colorArray[10] = { COLORS };

resistor_band_t *colors()
{
   return colorArray;
}

int color_code(resistor_band_t color)
{
   return color;
}
```

For more information, check the [Define consecutive values approach][approach-define-consecutive-values].


[define]: https://www.techonthenet.com/c_language/constants/create_define.php
[approach-define-consecutive-values]: https://exercism.org/tracks/c/exercises/resistor-colors/approaches/define-consecutive-values
