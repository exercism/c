#ifndef _COMPLEX_NUMBERS_H_
#define _COMPLEX_NUMBERS_H_

typedef struct {
   double real;
   double imag;
} complex_t;

complex_t c_add(const complex_t a, const complex_t b);
complex_t c_sub(const complex_t a, const complex_t b);
complex_t c_mul(const complex_t a, const complex_t b);
complex_t c_div(const complex_t a, const complex_t b);
double c_abs(const complex_t x);
complex_t c_conjugate(const complex_t x);
double c_real(const complex_t x);
double c_imag(const complex_t x);
complex_t c_exp(const complex_t x);

#endif
