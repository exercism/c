#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdint.h>

typedef struct
{
  int a, b, c;
} triplet_t;

typedef struct
{
  int count;
  triplet_t *triplets;
} triplets_t;

triplets_t *triplets_with_sum (uint16_t sum);

void free_triplets (triplets_t *pt);

#endif
