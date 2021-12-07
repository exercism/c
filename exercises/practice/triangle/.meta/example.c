#include "triangle.h"

#include <stdbool.h>

static bool triangle_equality(triangle_t sides)
{
   return (sides.a < (sides.b + sides.c) && sides.b < (sides.a + sides.c) &&
           sides.c < (sides.a + sides.b));
}

bool is_equilateral(triangle_t sides)
{
   return (triangle_equality(sides) && (sides.a == sides.b) &&
           (sides.b == sides.c));
}

bool is_isosceles(triangle_t sides)
{
   return (
       triangle_equality(sides) &&
       ((sides.a == sides.b) || (sides.b == sides.c) || (sides.a == sides.c)));
}

bool is_scalene(triangle_t sides)
{
   return (!(is_equilateral(sides)) && !(is_isosceles(sides)) &&
           triangle_equality(sides));
}
