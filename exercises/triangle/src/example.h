#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <stdbool.h>

typedef struct {
   double a;
   double b;
   double c;
} triangle_t;

bool is_equilateral(triangle_t input);
bool is_isosceles(triangle_t input);
bool is_scalene(triangle_t input);

#endif
