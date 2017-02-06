#ifndef TRIANGLE_H
#define TRIANGLE_H

typedef enum flavor {
   invalid,
   equilateral,
   isosceles,
   scalene
};

flavor kind(double a, double b, double c);

#endif
