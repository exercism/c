#ifndef SPACE_AGE_H
#define SPACE_AGE_H

typedef enum planet {
   mercury,
   venus,
   earth,
   mars,
   jupiter,
   saturn,
   uranus,
   neptune,
} planet_t;

float convert_planet_age(planet_t planet, const long input);

#endif
