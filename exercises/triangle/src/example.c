#include "triangle.h"

bool triangle_equality(triangle_t input)
{
   return (input.a < (input.b + input.c)
           && input.b < (input.a + input.c)
           && input.c < (input.a + input.b)
       );
}

bool is_equilateral(triangle_t input)
{
   return (triangle_equality(input)
           && (input.a == input.b)
           && (input.b == input.c)
       );
}

bool is_isosceles(triangle_t input)
{
   return (triangle_equality(input) && ((input.a == input.b)
                                        || (input.b == input.c)
                                        || (input.a == input.c))
       );
}

bool is_scalene(triangle_t input)
{
   return (!(is_equilateral(input))
           && !(is_isosceles(input))
           && triangle_equality(input)
       );
}
