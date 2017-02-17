#ifndef EXAMPLE_H
#define EXAMPLE_H

/* Number of seconds in a Earth year */
#define SECONDS_ON_EARTH_YEAR 31557600

/* Orbital period of each planet, in Earth years */
#define MERCURY_YEAR 0.2408467
#define VENUS_YEAR 0.61519726
#define MARS_YEAR 1.8808158
#define JUPITER_YEAR 11.862615
#define SATURN_YEAR 29.447498
#define URANUS_YEAR 84.016846
#define NEPTUNE_YEAR 164.79132

float convert_Mercury_Age(const long input);
float convert_Venus_Age(const long input);
float convert_Earth_Age(const long input);
float convert_Mars_Age(const long input);
float convert_Jupiter_Age(const long input);
float convert_Saturn_Age(const long input);
float convert_Uranus_Age(const long input);
float convert_Neptune_Age(const long input);

#endif
