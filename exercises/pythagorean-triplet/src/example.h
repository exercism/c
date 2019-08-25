#ifndef PYTHAGOREAN_TRIPLET
#define PYTHAGOREAN_TRIPLET

#include <stdint.h>
#include <stdlib.h>

#define LENGTH_OF_TRIPLET 3

typedef struct {
   size_t count;
   uint16_t triplets[][LENGTH_OF_TRIPLET];
} triplets_t;

triplets_t *triplets_with_sum(uint16_t sum);

void free_triplets(triplets_t * triplets);

#endif
