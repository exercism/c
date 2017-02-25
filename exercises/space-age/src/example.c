#include "space_age.h"

/* Number of seconds in a Earth year */
#define SECONDS_ON_EARTH_YEAR 31557600

/* Orbital period of each planet, in Earth years */
#define MERCURY_YEAR (0.2408467 * SECONDS_ON_EARTH_YEAR)
#define VENUS_YEAR (0.61519726 * SECONDS_ON_EARTH_YEAR)
#define MARS_YEAR (1.8808158 * SECONDS_ON_EARTH_YEAR)
#define JUPITER_YEAR (11.862615 * SECONDS_ON_EARTH_YEAR)
#define SATURN_YEAR (29.447498 * SECONDS_ON_EARTH_YEAR)
#define URANUS_YEAR (84.016846 * SECONDS_ON_EARTH_YEAR)
#define NEPTUNE_YEAR (164.79132 * SECONDS_ON_EARTH_YEAR)

float convert_earth_age(const long input)
{
   return input / SECONDS_ON_EARTH_YEAR;
}

float convert_mercury_age(const long input)
{
   return input / MERCURY_YEAR;
}

float convert_venus_age(const long input)
{
   return input / VENUS_YEAR;
}

float convert_mars_age(const long input)
{
   return input / MARS_YEAR;
}

float convert_jupiter_age(const long input)
{
   return input / JUPITER_YEAR;
}

float convert_saturn_age(const long input)
{
   return input / SATURN_YEAR;
}

float convert_uranus_age(const long input)
{
   return input / URANUS_YEAR;
}

float convert_neptune_age(const long input)
{
   return input / NEPTUNE_YEAR;
}
