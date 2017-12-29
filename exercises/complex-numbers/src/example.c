#include "complex_numbers.h"
#include <math.h>

static double square(double x)
{
   return x * x;
}

complex_t c_add(complex_t a, complex_t b)
{
   complex_t result;
   result.real = a.real + b.real;
   result.imag = a.imag + b.imag;

   return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t result;
   result.real = a.real - b.real;
   result.imag = a.imag - b.imag;

   return result;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t result;
   result.real = a.real * b.real - a.imag * b.imag;
   result.imag = a.imag * b.real + a.real * b.imag;

   return result;
}

complex_t c_div(complex_t a, complex_t b)
{
   double denominator = square(b.real) + square(b.imag);

   complex_t result;
   result.real = (a.real * b.imag + a.imag * b.real) / denominator;
   result.imag = (a.imag * b.real - a.real * b.imag) / denominator;

   return result;
}

double c_abs(complex_t x)
{
   return sqrt(square(x.real) + square(x.imag));
}

complex_t c_conjugate(complex_t x)
{
   complex_t result;
   result.real = x.real;
   result.imag = -(x.imag);

   return result;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   double real_exp = exp(x.real);

   complex_t result;
   result.real = real_exp * cos(x.imag);
   result.imag = real_exp * sin(x.imag);

   return result;
}
