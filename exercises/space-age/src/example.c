#include "example.h"

float convert_Earth_Age(const long input)
{
   return input/SECONDS_ON_EARTH_YEAR;
}

float convert_Mercury_Age(const long input)
{
   return convert_Earth_Age(input)/MERCURY_YEAR;
}

float convert_Venus_Age(const long input)
{
   return convert_Earth_Age(input)/VENUS_YEAR;
}

float convert_Mars_Age(const long input)
{
   return convert_Earth_Age(input)/MARS_YEAR;
}

float convert_Jupiter_Age(const long input)
{
   return convert_Earth_Age(input)/JUPITER_YEAR;
}

float convert_Saturn_Age(const long input)
{
   return convert_Earth_Age(input)/SATURN_YEAR;
}

float convert_Uranus_Age(const long input)
{
   return convert_Earth_Age(input)/URANUS_YEAR;
}

float convert_Neptune_Age(const long input)
{
   return convert_Earth_Age(input)/NEPTUNE_YEAR;
}
