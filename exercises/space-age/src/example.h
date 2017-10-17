#ifndef SPACE_AGE_H
#define SPACE_AGE_H

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

float convert_planet_age(planet_t planet, const long input);

#endif
