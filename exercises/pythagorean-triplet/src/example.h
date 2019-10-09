#ifndef PYTHAGOREAN_TRIPLET
#define PYTHAGOREAN_TRIPLET

#include <stdint.h>
#include <stdlib.h>

typedef struct {
   uint16_t a, b, c;
} triplet_t;

typedef struct {
   size_t count;
   triplet_t triplets[];
} triplets_t;

triplets_t *triplets_with_sum(uint16_t sum);

void free_triplets(triplets_t * triplets);

#endif
