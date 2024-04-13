#ifndef YACHT_H
#define YACHT_H

#include <stdint.h>

typedef enum {
   ONES,
   TWOS,
   THREES,
   FOURS,
   FIVES,
   SIXES,
   FULL_HOUSE,
   FOUR_OF_A_KIND,
   LITTLE_STRAIGHT,
   BIG_STRAIGHT,
   CHOICE,
   YACHT
} category_t;

typedef struct {
   uint8_t faces[5];
} dice_t;

int score(dice_t dice, category_t category);

#endif
