#ifndef ALLERGIES_H
#define ALLERGIES_H

typedef enum {
   allergen_eggs = 0,
   allergen_peanuts,
   allergen_shellfish,
   allergen_strawberries,
   allergen_tomatoes,
   allergen_chocolate,
   allergen_pollen,
   allergen_cats,
   allergen_count
} allergen_t;

typedef struct {
   int count;
   allergen_t *allergens;
} allergen_list_t;

#endif
