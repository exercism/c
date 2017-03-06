#ifndef SPACE_AGE_H
#define SPACE_AGE_H

typedef enum planets {
   mercury = 0,
   venus,
   earth,
   mars,
   jupiter,
   saturn,
   uranus,
   neptune,
   max_planet = neptune
} Planets;

float convert_planet_age(Planets planet, const long input);

#endif
