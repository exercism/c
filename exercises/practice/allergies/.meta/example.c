#include "allergies.h"
#include <stdlib.h>

bool is_allergic_to(allergen_t allergen, unsigned int score)
{
   return ((score & (1 << allergen)) != 0);
}

allergen_list_t get_allergens(unsigned int score)
{
   allergen_list_t list = {
      .count = 0,
      .allergens = { 0 },
   };

   for (allergen_t allergen = 0; allergen < ALLERGEN_COUNT; ++allergen) {
      if (is_allergic_to(allergen, score)) {
         list.allergens[allergen] = true;
         ++list.count;
      }
   }
   return list;
}
