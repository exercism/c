# Array index

**space_age.h**

```c
#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

float age(planet_t planet, int64_t seconds);

#endif
```

**space_age.c**

```c
#include "space_age.h"

static const int EARTH_YEAR_SECONDS = 31557600;
static const double RATIOS [] = {
    0.2408467, 0.61519726, 1.0, 1.8808158, // inner planets
    11.862615, 29.447498, 84.016846, 164.79132 // outer planets
};

float age(planet_t planet, int64_t seconds){
    return planet >= 0 && planet <= 7 ?
        seconds / EARTH_YEAR_SECONDS / RATIOS[planet] : -1;
}
```

In the header is defined an enum with values `0` through `7` for the planets `MERCURY` through `NEPTUNE`.

In the source file an array of the planet orbit ratios is defined, with the index of each ratio corresponding with the planet's value in the enum.
It also defines the earth year in seconds as a [`const`][const].
The `const` value is given a meaningful name instead of using `31557600` as a [magic number][magic-numbers].

The `age` function takes an argument of that `enum` along with the `seconds`.

It uses a [ternary operator][ternary] operator to test if the `planet` value is in the valid range.
If so, it divides the `seconds` by the earth year seconds and divides the result by the orbit ratio in the ratio array at the index determined by the `planet` value.
The result of all that is returned by function.

If the `planet` value is not in the valid range, then the ternary operator returns `-1` for an error value, which is returned by the function.

[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
[const]: https://www.geeksforgeeks.org/const-qualifier-in-c/
[magic-numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
