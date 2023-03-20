# `hypot` for radius

**darts.h**

```c
#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>

typedef struct
{
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t);
#endif
```

**darts.c**

```c
#include "darts.h"
#include <math.h>
#include <stdbool.h>

const float INNER_RING = 1.0f;
const float MIDDLE_RING = 5.0f;
const float OUTER_RING = 10.0f;

static float radius(coordinate_t throw)
{
   return hypot(throw.x, throw.y);
}

static bool throw(float radius, float ring)
{
   return radius <= ring;
}

uint8_t score(coordinate_t dart_throw)
{
   float is_within = radius(dart_throw);

   if (throw(is_within, INNER_RING)) {
      return 10;
   }
   if (throw(is_within, MIDDLE_RING)) {
      return 5;
   }
   if (throw(is_within, OUTER_RING)) {
      return 1;
   }
   return 0;
}
```

This approach starts by defining [`const`][const] values for the rings.
The `const` values are given meaningful names instead of using the float literals as [magic numbers][magic-numbers].

The `radius` function uses the [`hypot`][hypot] function to calculate the [radius][radius] of the dart throw from the `x` and `y` coordinates.

The `throw` function returns if the radius passed in is within the ring passed in.

The `score` function uses the `radius` function to calculate the radius of the dart throw.

Due to the naming of the function and varables, the `if` statements read much like natural language.

The `throw` function is passed the dart throw radius and the ring.
If it returns `true`, then the function returns with the score for throwing within that ring.

If the throw is not within a defined ring, then the function returns `0`.

[magic-numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
[const]: https://www.geeksforgeeks.org/const-qualifier-in-c/
[hypot]: https://en.cppreference.com/w/c/numeric/math/hypot
[radius]: https://www.mathopenref.com/coordbasiccircle.html
