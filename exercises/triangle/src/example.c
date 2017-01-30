#include "triangle.h"

int triangle_equality(double a, double b, double c)
{
   return (a < (b + c) && b < (a + c) && c < (a + b));
}

int kind(double a, double b, double c)
{
   if (a == 0 || b == 0 || c == 0) {
      return error;
   }
   if (a < 0 || b < 0 || c < 0 || !triangle_equality(a, b, c)) {
      return error;
   }
   if (a == b && b == c) {
      return equilateral;
   }
   if (a == b || b == c || a == c) {
      return isosceles;
   }
   return scalene;
}
