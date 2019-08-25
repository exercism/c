#include "pythagorean_triplet.h"

static triplets_t *no_triplets(void)
{
   triplets_t *triplets = malloc(sizeof(triplets_t));

   if (triplets)
      triplets->count = 0;

   return triplets;
}

static triplets_t *add_triplet(triplets_t * triplets, uint16_t a, uint16_t b,
                               uint16_t c)
{
   size_t count = 0;
   if (triplets)
      count = triplets->count;

   triplets_t *new_triplets = realloc(triplets, sizeof(triplets_t) +
                                      (sizeof(uint16_t) * LENGTH_OF_TRIPLET) *
                                      ++count);
   if (new_triplets) {
      triplets = new_triplets;
      triplets->count = count;
      triplets->triplets[count - 1][0] = a;
      triplets->triplets[count - 1][1] = b;
      triplets->triplets[count - 1][2] = c;
   } else {
      free(triplets);
      triplets = NULL;
   }

   return triplets;
}

triplets_t *triplets_with_sum(uint16_t sum)
{
   triplets_t *triplets = no_triplets();

   for (uint16_t a = 0; a < sum / 3; ++a) {
      for (uint16_t b = a; b < sum / 2; ++b) {
         uint16_t c = sum - a - b;
         if (a * a + b * b == c * c) {
            triplets = add_triplet(triplets, a, b, c);
            break;
         }
      }
   }
   return triplets;
}

void free_triplets(triplets_t * triplets)
{
   free(triplets);
}
