# Introduction

There are serveral ways to solve Darts.
One approach is to use the [`hypot`][hypot] function to get the [radius][radius] of the throw.

## Approach: `hypot` for radius

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

static bool hit(float throw, float ring)
{
   return throw <= ring;
}

uint8_t score(coordinate_t throw)
{
   float within = radius(throw);

   if (hit(within, INNER_RING)) {
      return 10;
   }
   if (hit(within, MIDDLE_RING)) {
      return 5;
   }
   if (hit(within, OUTER_RING)) {
      return 1;
   }
   return 0;
}
```

For more information, check the [`hypot` for radius approach][approach-hypot-for-radius].

[approach-hypot-for-radius]: https://exercism.org/tracks/c/exercises/darts/approaches/hypot-for-radius
[hypot]: https://en.cppreference.com/w/c/numeric/math/hypot
[radius]: https://www.mathopenref.com/coordbasiccircle.html
