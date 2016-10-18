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

bool is_allergic_to(Allergen_t allergen, unsigned int score)
{
   return ((score & scores[allergen]) == scores[allergen]);
}

void get_allergens(int score, Allergen_List_t * list)
{
   list->allergens = calloc(Allergen_Count, sizeof(Allergen_t));
   list->count = 0;

   for (Allergen_t allergen = 0; allergen < Allergen_Count; allergen++) {
      if (is_allergic_to(allergen, score)) {
         score -= scores[allergen];
         list->allergens[list->count] = allergen;
         list->count++;
      }
   }
}
