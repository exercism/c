#ifndef _ALLERGIES_H
#define _ALLERGIES_H

#include <stdbool.h>

typedef enum {
   Allergen_Eggs = 0,
   Allergen_Peanuts,
   Allergen_Shellfish,
   Allergen_Strawberries,
   Allergen_Tomatoes,
   Allergen_Chocolate,
   Allergen_Pollen,
   Allergen_Cats,
   Allergen_Count
} Allergen_t;

typedef struct {
   int count;
   Allergen_t *allergens;
} Allergen_List_t;

bool is_allergic_to(Allergen_t allergen, unsigned int score);
void get_allergens(int score, Allergen_List_t * list);

#endif
