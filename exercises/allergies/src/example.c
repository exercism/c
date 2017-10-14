#include "allergies.h"
#include <stdlib.h>

static const unsigned int scores[] = {
   1,
   2,
   4,
   8,
   16,
   32,
   64,
   128
};

bool is_allergic_to(allergen_t allergen, unsigned int score)
{
   return ((score & scores[allergen]) == scores[allergen]);
}

void get_allergens(unsigned int score, allergen_list_t * list)
{
   list->allergens = calloc(ALLERGEN_COUNT, sizeof(allergen_t));
   list->count = 0;

   for (allergen_t allergen = 0; allergen < ALLERGEN_COUNT; allergen++) {
      if (is_allergic_to(allergen, score)) {
         score -= scores[allergen];
         list->allergens[list->count] = allergen;
         list->count++;
      }
   }
}
