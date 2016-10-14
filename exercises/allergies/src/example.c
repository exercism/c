#include "allergies.h"
#include <stdlib.h>

static const int scores[] =
{
   1,
   2,
   4,
   8,
   16,
   32,
   64,
   128
};

bool is_allergic_to(Allergen_t allergen, int score)
{
   return ((score & scores[allergen]) == scores[allergen]);
}

void get_allergens(int score, Allergen_List_t *list)
{
   list->allergens = calloc(0, sizeof(Allergen_t) * Allergen_Last);

   for (Allergen_t allergen = Allergen_First; allergen <= Allergen_Last; allergen++) {
      if (is_allergic_to(allergen, score)) {
         score -= scores[allergen];
         list->allergens[list->count] = allergen;
         list->count++;
      }
   }
}
