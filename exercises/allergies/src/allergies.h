#ifndef ALLERGIES_H
#define ALLERGIES_H

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

#endif
