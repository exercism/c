#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <stdbool.h>

typedef struct {
   double point_a;
   double point_b;
   double point_c;
} Triangle_t;

bool is_equilateral(Triangle_t * input);
bool is_isosceles(Triangle_t * input);
bool is_scalene(Triangle_t * input);

#endif
