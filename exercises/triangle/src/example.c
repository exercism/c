#include "triangle.h"

bool triangle_equality(Triangle_t * input)
{
   return (input->point_a > 0
           && input->point_b > 0
           && input->point_c > 0
           && input->point_a < (input->point_b + input->point_c)
           && input->point_b < (input->point_a + input->point_c)
           && input->point_c < (input->point_a + input->point_b)
       );
}

bool is_equilateral(Triangle_t * input)
{
   return (triangle_equality(input)
           && (input->point_a == input->point_b)
           && (input->point_b == input->point_c)
       );
}

bool is_isosceles(Triangle_t * input)
{
   return (triangle_equality(input) &&
           ((input->point_a == input->point_b)
            || (input->point_b == input->point_c)
            || (input->point_a == input->point_c))
       );
}

bool is_scalene(Triangle_t * input)
{
   return (!(is_equilateral(input))
           && !(is_isosceles(input))
           && triangle_equality(input)
       );
}
