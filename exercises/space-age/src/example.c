#include "space_age.h"

/* Number of seconds in a Earth year */
#define EARTH 31557600

/* Orbital period of each planet, in Earth years */
#define MERCURY (0.2408467 * EARTH)
#define VENUS (0.61519726 * EARTH)
#define MARS (1.8808158 * EARTH)
#define JUPITER (11.862615 * EARTH)
#define SATURN (29.447498 * EARTH)
#define URANUS (84.016846 * EARTH)
#define NEPTUNE (164.79132 * EARTH)

float convert_planet_age(Planets planet, const long input)
{
   switch (planet) {
   case mercury:
      return input / MERCURY;

   case venus:
      return input / VENUS;

   case mars:
      return input / MARS;

   case jupiter:
      return input / JUPITER;

   case saturn:
      return input / SATURN;

   case uranus:
      return input / URANUS;

   case neptune:
      return input / NEPTUNE;

   default:
      return input / EARTH;
   };

}
