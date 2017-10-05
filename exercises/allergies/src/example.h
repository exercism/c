#ifndef ALLERGIES_H
#define ALLERGIES_H

#include <stdbool.h>

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

bool is_allergic_to(allergen_t allergen, unsigned int score);
void get_allergens(unsigned int score, allergen_list_t * list);

#endif
