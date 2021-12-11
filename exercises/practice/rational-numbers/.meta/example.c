#include "rational_numbers.h"
#include <stdlib.h>
#include <math.h>

static float nth_root(float x, float n)
{
   return pow(x, 1. / n);
}

static int16_t greatest_common_divisor(int n, int m)
{
   int16_t remainder;
   while (n != 0) {
      remainder = m % n;
      m = n;
      n = remainder;
   }
   return m;
}

rational_t reduce(rational_t r)
{
   if (r.numerator == 0)   // shortcut rational of 0
      return (rational_t){ 0, 1 };

   int16_t n = greatest_common_divisor(r.numerator, r.denominator);
   int16_t numerator = r.numerator / n;
   int16_t denominator = r.denominator / n;

   if (denominator < 0) {   // reduce sign
      denominator = -denominator;
      numerator = -numerator;
   }

   return (rational_t){ numerator, denominator };
}

rational_t add(rational_t r1, rational_t r2)
{
   // r1 + r2 = a1/b1 + a2/b2 = (a1 * b2 + a2 * b1) / (b1 * b2)
   int16_t numerator =
       r1.numerator * r2.denominator + r2.numerator * r1.denominator;
   int16_t denominator = 1;
   if (numerator != 0)
      denominator = r1.denominator * r2.denominator;
   return reduce((rational_t){ numerator, denominator });
}

rational_t subtract(rational_t r1, rational_t r2)
{
   // r1 - r2 = a1/b1 - a2/b2 = (a1 * b2 - a2 * b1) / (b1 * b2)
   int16_t numerator =
       r1.numerator * r2.denominator - r2.numerator * r1.denominator;
   int16_t denominator = 1;
   if (numerator != 0)
      denominator = r1.denominator * r2.denominator;
   return reduce((rational_t){ numerator, denominator });
}

rational_t multiply(rational_t r1, rational_t r2)
{
   // r1 * r2 = (a1 * a2) / (b1 * b2)
   int16_t numerator = r1.numerator * r2.numerator;
   int16_t denominator = r1.denominator * r2.denominator;
   return reduce((rational_t){ numerator, denominator });
}

rational_t divide(rational_t r1, rational_t r2)
{
   // r1 / r2 = (a1 * b2) / (a2 * b1)
   int16_t numerator = r1.numerator * r2.denominator;
   int16_t denominator = r2.numerator * r1.denominator;
   if (denominator < 0) {   // reduce sign
      denominator = -denominator;
      numerator = -numerator;
   }
   return reduce((rational_t){ numerator, denominator });
}

rational_t absolute(rational_t r)
{
   // |a/b| = |a|/|b|
   int16_t numerator = abs(r.numerator);
   int16_t denominator = abs(r.denominator);
   return reduce((rational_t){ numerator, denominator });
}

rational_t exp_rational(rational_t r, uint16_t n)
{
   if (n == 0)   // shortcut power of 0
      return (rational_t){ 1, 1 };
   if (r.numerator == 0)   // shortcut rational of 0
      return (rational_t){ 0, 1 };

   // r^n = (a^|n|)/(b^|n|)
   int16_t numerator = pow(r.numerator, n);
   int16_t denominator = pow(r.denominator, n);
   return reduce((rational_t){ numerator, denominator });
}

float exp_real(uint16_t n, rational_t r)
{
   if (r.numerator == 0)   // shortcut power of 0
      return 1.0f;

   r = reduce(r);

   // x^(a/b) = root(x^a, b), where root(p, q) is the qth root of p
   float p = pow(n, r.numerator);
   return nth_root(p, r.denominator);
}
