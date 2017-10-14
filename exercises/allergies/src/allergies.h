#ifndef ALLERGIES_H
#define ALLERGIES_H

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT
} allergen_t;

typedef struct {
   int count;
   allergen_t *allergens;
} allergen_list_t;

#endif
