#include "space_age.h"

/* Number of seconds in a Earth year */
#define EARTH 31557600

/* Orbital period of each planet, in Earth years */
static const float factors[8] = {
   EARTH * 0.2408467,           // Mercury
   EARTH * 0.61519726,          // Venus
   EARTH * 1,                   // Earth
   EARTH * 1.8808158,           // Mars
   EARTH * 11.862615,           // Jupiter
   EARTH * 29.447498,           // Saturn
   EARTH * 84.016846,           // Uranus
   EARTH * 164.79132            // Neptune
};

float convert_planet_age(planet_t planet, const long input)
{
   return input / factors[planet];
}
