#ifndef RATIONAL_NUMBERS
#define RATIONAL_NUMBERS

#include <stdint.h>

typedef struct {
   int16_t numerator, denominator;
} rational_t;

rational_t add(rational_t r1, rational_t r2);

rational_t sub(rational_t r1, rational_t r2);

rational_t mul(rational_t r1, rational_t r2);

rational_t div(rational_t r1, rational_t r2);

rational_t abs(rational_t r);

rational_t exp_rational(rational_t r, uint16_t n);

float exp_real(uint16_t n, rational_t r);

rational_t reduce(rational_t r);

#endif
