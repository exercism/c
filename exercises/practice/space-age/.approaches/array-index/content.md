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

TODO
