#ifndef SIEVE_H
#define SIEVE_H

#define MAX_LIMIT_TESTED (1000)

typedef unsigned int primesArray_t[MAX_LIMIT_TESTED];

unsigned int sieve(const unsigned int limit, primesArray_t primes);

#endif
