#include "zebra_puzzle.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

enum { NUM_HOUSES = 5 };

static inline void swap(int *a, int *b)
{
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

/// Transform `order` into its next lexicographically larger permutation.
///
/// return true if on success
/// return false if parameter is already the largest possible permutation
static bool next_permutation(int order[NUM_HOUSES], int by_value[NUM_HOUSES])
{
   const size_t len = NUM_HOUSES;

   // find the rightmost element that is smaller than its right neighbor
   size_t idx1 = len - 2;
   while (idx1 < len && order[idx1] >= order[idx1 + 1])
      --idx1;

   // if no such element has been found we've reached the final permutation
   if (idx1 >= len)
      return false;

   // find the rightmost element that is larger than order[idx1]
   size_t idx2 = len - 1;
   while (order[idx1] >= order[idx2])
      --idx2;

   // permute the elements
   swap(order + idx1, order + idx2);
   for (size_t a = idx1 + 1, b = len - 1; a < b; ++a, --b)
      swap(order + a, order + b);

   // update the affected elements of by_value
   for (size_t i = idx1; i < NUM_HOUSES; ++i)
      by_value[order[i]] = i;
   return true;
}

enum nationality { ENGLISH, JAPANESE, NORWEGIAN, SPANISH, UKRAINIAN };
enum color { BLUE, GREEN, IVORY, RED, YELLOW };
enum animal { DOG, FOX, HORSE, SNAILS, ZEBRA };
enum drink { COFFEE, MILK, ORANGE_JUICE, TEA, WATER };
enum smoke { CHESTERFIELD, KOOL, LUCKY_STRIKE, OLD_GOLD, PARLIAMENT };

static void solve(const char **out_drinks_water, const char **out_owns_zebra)
{
   int num_solutions = 0;
   int drinks_water = -1;
   int owns_zebra = -1;

   int colors[] = { BLUE, GREEN, IVORY, RED, YELLOW };
   int house_by_color[] = { 0, 1, 2, 3, 4 };
   do {
      // 6. The green house is immediately to the right of the ivory house.
      if (house_by_color[GREEN] - 1 != house_by_color[IVORY])
         continue;

      int nationalities[] = { ENGLISH, JAPANESE, NORWEGIAN, SPANISH,
                              UKRAINIAN };
      int house_by_nationality[] = { 0, 1, 2, 3, 4 };
      do {
         // 2. The Englishman lives in the red house.
         if (house_by_nationality[ENGLISH] != house_by_color[RED])
            continue;

         // 10. The Norwegian lives in the first house.
         if (house_by_nationality[NORWEGIAN] != 0)
            continue;

         // 15. The Norwegian lives next to the blue house.
         if (abs(house_by_nationality[NORWEGIAN] - house_by_color[BLUE]) != 1)
            continue;

         int pets[] = { DOG, FOX, HORSE, SNAILS, ZEBRA };
         int house_by_pet[] = { 0, 1, 2, 3, 4 };
         do {
            // 3. The Spaniard owns the dog.
            if (house_by_nationality[SPANISH] != house_by_pet[DOG])
               continue;

            int beverages[] = { COFFEE, MILK, ORANGE_JUICE, TEA, WATER };
            int house_by_beverage[] = { 0, 1, 2, 3, 4 };
            do {
               // 4. Coffee is drunk in the green house.
               if (house_by_beverage[COFFEE] != house_by_color[GREEN])
                  continue;

               // 5. The Ukrainian drinks tea.
               if (house_by_nationality[UKRAINIAN] != house_by_beverage[TEA])
                  continue;

               // 9. Milk is drunk in the middle house.
               if (house_by_beverage[MILK] != NUM_HOUSES / 2)
                  continue;

               int brands[] = { CHESTERFIELD, KOOL, LUCKY_STRIKE, OLD_GOLD,
                                PARLIAMENT };
               int house_by_brand[] = { 0, 1, 2, 3, 4 };
               do {
                  // 7. The Old Gold smoker owns snails.
                  if (house_by_brand[OLD_GOLD] != house_by_pet[SNAILS])
                     continue;

                  // 8. Kools are smoked in the yellow house.
                  if (house_by_brand[KOOL] != house_by_color[YELLOW])
                     continue;

                  // 11. The man who smokes Chesterfields lives in the
                  //     house next to the man with the fox.
                  if (abs(house_by_brand[CHESTERFIELD] - house_by_pet[FOX]) !=
                      1)
                     continue;

                  // 12. Kools are smoked in the house next to the house
                  //     where the horse is kept.
                  if (abs(house_by_brand[KOOL] - house_by_pet[HORSE]) != 1)
                     continue;

                  // 13. The Lucky Strike smoker drinks orange juice.
                  if (house_by_brand[LUCKY_STRIKE] !=
                      house_by_beverage[ORANGE_JUICE])
                     continue;

                  // 14. The Japanese smokes Parliaments.
                  if (house_by_nationality[JAPANESE] !=
                      house_by_brand[PARLIAMENT])
                     continue;

                  assert(num_solutions == 0);
                  ++num_solutions;
                  drinks_water = nationalities[house_by_beverage[WATER]];
                  owns_zebra = nationalities[house_by_pet[ZEBRA]];

               } while (next_permutation(brands, house_by_brand));
            } while (next_permutation(beverages, house_by_beverage));
         } while (next_permutation(pets, house_by_pet));
      } while (next_permutation(nationalities, house_by_nationality));
   } while (next_permutation(colors, house_by_color));

   assert(num_solutions == 1);
   switch (drinks_water) {
      case ENGLISH:
         *out_drinks_water = "English";
         break;
      case JAPANESE:
         *out_drinks_water = "Japanese";
         break;
      case NORWEGIAN:
         *out_drinks_water = "Norwegian";
         break;
      case SPANISH:
         *out_drinks_water = "Spanish";
         break;
      case UKRAINIAN:
         *out_drinks_water = "Ukrainian";
         break;
      default:
         assert(false);
   }
   switch (owns_zebra) {
      case ENGLISH:
         *out_owns_zebra = "English";
         break;
      case JAPANESE:
         *out_owns_zebra = "Japanese";
         break;
      case NORWEGIAN:
         *out_owns_zebra = "Norwegian";
         break;
      case SPANISH:
         *out_owns_zebra = "Spanish";
         break;
      case UKRAINIAN:
         *out_owns_zebra = "Ukrainian";
         break;
      default:
         assert(false);
   }
}

const char *drinks_water(void)
{
   const char *result, *dummy;
   solve(&result, &dummy);
   return result;
}

const char *owns_zebra(void)
{
   const char *result, *dummy;
   solve(&dummy, &result);
   return result;
}
