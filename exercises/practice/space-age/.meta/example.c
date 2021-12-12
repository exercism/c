#include "space_age.h"
#include <stdbool.h>

/* Number of seconds in a Earth year */
#define EARTH_YEAR_IN_SECONDS 31557600

/* Orbital period of each planet, in Earth years */
static const float factors[8] = {
   EARTH_YEAR_IN_SECONDS * 0.2408467,    // Mercury
   EARTH_YEAR_IN_SECONDS * 0.61519726,   // Venus
   EARTH_YEAR_IN_SECONDS * 1,            // Earth
   EARTH_YEAR_IN_SECONDS * 1.8808158,    // Mars
   EARTH_YEAR_IN_SECONDS * 11.862615,    // Jupiter
   EARTH_YEAR_IN_SECONDS * 29.447498,    // Saturn
   EARTH_YEAR_IN_SECONDS * 84.016846,    // Uranus
   EARTH_YEAR_IN_SECONDS * 164.79132     // Neptune
};

static bool is_planet(planet_t planet)
{
   bool result = false;

   switch (planet) {
      case MERCURY:
      case VENUS:
      case EARTH:
      case MARS:
      case JUPITER:
      case SATURN:
      case URANUS:
      case NEPTUNE:
         result = true;
   }

   return result;
}

float age(planet_t planet, int64_t seconds)
{
   return (is_planet(planet)) ? seconds / factors[planet] : -1.0;
}
