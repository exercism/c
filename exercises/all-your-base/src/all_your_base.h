#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stddef.h>
#include <stdint.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int16_t digits[DIGITS_ARRAY_SIZE], int16_t fromBase,
              int16_t toBase, size_t numDigits);

#endif
