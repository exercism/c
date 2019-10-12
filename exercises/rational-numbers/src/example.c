#include "rational_numbers.h"
#include <math.h>

static int16_t absi(int16_t n)
{
   const int16_t mask = n >> 15;
   return (n + mask) ^ mask;
}

static float nth_root(float x, float n)
{
   return pow(x, 1. / n);
}

static int16_t gcd(int n, int m)
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
   if (r.numerator == 0)        // shortcut rational of 0
      return (rational_t) {
      0, 1};

   int16_t n = gcd(r.numerator, r.denominator);
   int16_t numerator = r.numerator / n;
   int16_t denominator = r.denominator / n;

   if (denominator < 0) {       // reduce sign
      denominator = -denominator;
      numerator = -numerator;
   }

   return (rational_t) {
   numerator, denominator};
}

rational_t add(rational_t r1, rational_t r2)
{
   // r1 + r2 = a1/b1 + a2/b2 = (a1 * b2 + a2 * b1) / (b1 * b2)
   int16_t numerator =
       r1.numerator * r2.denominator + r2.numerator * r1.denominator;
   int16_t denominator = 1;
   if (numerator != 0)
      denominator = r1.denominator * r2.denominator;
   return (rational_t) {
   numerator, denominator};
}

rational_t sub(rational_t r1, rational_t r2)
{
   // r1 - r2 = a1/b1 - a2/b2 = (a1 * b2 - a2 * b1) / (b1 * b2)
   int16_t numerator =
       r1.numerator * r2.denominator - r2.numerator * r1.denominator;
   int16_t denominator = 1;
   if (numerator != 0)
      denominator = r1.denominator * r2.denominator;
   return (rational_t) {
   numerator, denominator};
}

rational_t mul(rational_t r1, rational_t r2)
{
   // r1 * r2 = (a1 * a2) / (b1 * b2)
   int16_t numerator = r1.numerator * r2.numerator;
   int16_t denominator = r1.denominator * r2.denominator;
   return reduce((rational_t) {
                 numerator, denominator}
   );
}

rational_t div(rational_t r1, rational_t r2)
{
   // r1 / r2 = (a1 * b2) / (a2 * b1)
   int16_t numerator = r1.numerator * r2.denominator;
   int16_t denominator = r2.numerator * r1.denominator;
   if (denominator < 0) {       // reduce sign
      denominator = -denominator;
      numerator = -numerator;
   }
   return (rational_t) {
   numerator, denominator};
}

rational_t abs(rational_t r)
{
   // |a/b| = |a|/|b|
   int16_t numerator = absi(r.numerator);
   int16_t denominator = absi(r.denominator);
   return (rational_t) {
   numerator, denominator};
}

rational_t exp_rational(rational_t r, uint16_t n)
{
   if (n == 0)                  // shortcut power of 0
      return (rational_t) {
      1, 1};
   if (r.numerator == 0)        // shortcut rational of 0
      return (rational_t) {
      0, 1};

   // r^n = (a^|n|)/(b^|n|)
   int16_t numerator = pow(r.numerator, n);
   int16_t denominator = pow(r.denominator, n);
   return (rational_t) {
   numerator, denominator};
}

float exp_real(uint16_t n, rational_t r)
{
   if (r.numerator == 0)        // shortcut power of 0
      return 1.0f;

   // x^(a/b) = root(x^a, b), where root(p, q) is the qth root of p
   float p = pow(n, r.numerator);
   return nth_root(p, r.denominator);
}
