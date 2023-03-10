# Define consecutive values

**resistor_color.h**

```c
#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H
#include <stdint.h>

#define COLORS                                                                 \
   BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum RESISTOR_BANDS { COLORS } resistor_band_t;

uint16_t color_code(resistor_band_t color);
resistor_band_t *colors(void);

#endif
```

**resistor_color.c**

```c
#include "resistor_color.h"

static resistor_band_t color_array[10] = { COLORS };

resistor_band_t *colors(void)
{
   return color_array;
}

uint16_t color_code(resistor_band_t color)
{
   return color;
}
```

The header file starts by using the [`#define`][define] directive to set the consectuve values.
After the `COLORS` symbol is a [line continuation character][continuation].
Since the `COLORS` symbol is not followed by a single value but by a series of comma-separated symbols, each of those symbols is given
a default value, starting with `0`.
The `COLORS` symbol expands to that series of values.
The line continuation character is used only because the length of the series of values would make the line exceed `80` characters.

The `COLORS` values are passed into a [`typedef`][typedef].
The `typedef` uses the series of `COLORS` values to create the new `enum` type of `resistor_band_t`.

In the source file, the same series of `COLORS` values is used to initialize the `color_array`.

The `colors` function returns the `color_array`.

The `color_code` function returns the `resistor_band_t` value passed in, since its underlying value is an `int` with the expected value.

[define]: https://www.techonthenet.com/c_language/constants/create_define.php
[continuation]: https://gcc.gnu.org/onlinedocs/gcc-3.2.3/cpp/Initial-processing.html#:~:text=A%20continued%20line%20is%20a,lines%20only%20at%20white%20space
[typedef]: https://www.tutorialspoint.com/cprogramming/c_typedef.htm
