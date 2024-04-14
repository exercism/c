#include "yacht.h"

#include <assert.h>

static int number_of_x(dice_t dice, int x)
{
   int sum = 0;
   for (int i = 0; i < 5; ++i) {
      if (dice.faces[i] == x)
         sum += x;
   }
   return sum;
}

typedef struct {
   int faces[6];
} count_t;

static count_t count(const dice_t dice)
{
   count_t counts = { 0 };
   for (int i = 0; i < 5; ++i) {
      assert(dice.faces[i] >= 1 && dice.faces[i] <= 6);
      counts.faces[dice.faces[i] - 1] += 1;
   }
   return counts;
}

static int has_count(count_t counts, int n)
{
   for (int i = 0; i < 6; ++i) {
      if (counts.faces[i] == n) {
         return i + 1;
      }
   }
   return 0;
}

static int sum(dice_t dice)
{
   int s = 0;
   for (int i = 0; i < 5; ++i) {
      s += dice.faces[i];
   }
   return s;
}

int score(dice_t dice, category_t category)
{
   switch (category) {
      case ONES:
         return number_of_x(dice, 1);
      case TWOS:
         return number_of_x(dice, 2);
      case THREES:
         return number_of_x(dice, 3);
      case FOURS:
         return number_of_x(dice, 4);
      case FIVES:
         return number_of_x(dice, 5);
      case SIXES:
         return number_of_x(dice, 6);
      case FULL_HOUSE: {
         const count_t counts = count(dice);
         if (has_count(counts, 3) && has_count(counts, 2)) {
            return sum(dice);
         }
         return 0;
      }
      case FOUR_OF_A_KIND: {
         const count_t counts = count(dice);
         const int face_with_count_4 = has_count(counts, 4);
         const int face_with_count_1 = has_count(counts, 1);
         const int face_with_count_5 = has_count(counts, 5);
         if ((face_with_count_4 && face_with_count_1) || face_with_count_5) {
            return 4 * (face_with_count_4 + face_with_count_5);
         }
         return 0;
      }
      case LITTLE_STRAIGHT: {
         const count_t counts = count(dice);
         for (int face = 0; face < 5; ++face) {
            if (counts.faces[face] != 1)
               return 0;
         }
         return 30;
      }
      case BIG_STRAIGHT: {
         const count_t counts = count(dice);
         for (int face = 1; face < 6; ++face) {
            if (counts.faces[face] != 1)
               return 0;
         }
         return 30;
      }
      case CHOICE:
         return sum(dice);
      case YACHT: {
         const count_t counts = count(dice);
         if (has_count(counts, 5))
            return 50;
         return 0;
      }
   }
   return 0;
}
