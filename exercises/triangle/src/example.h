#ifndef TRIANGLE_H
#define TRIANGLE_H

enum flavor {
   invalid,
   equilateral,
   isosceles,
   scalene
};

enum flavor kind(double a, double b, double c);

#endif
