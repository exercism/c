#include "dnd_character.h"

#include <stdlib.h>
#include <math.h>

static int dice_roll(void)
{
   // NB: This suffers from modulo bias, but probably good enough for the
   // purpose of this exercise.
   return 1 + rand() % 6;
}

int ability(void)
{
   const int rolls[4] = { dice_roll(), dice_roll(), dice_roll(), dice_roll() };
   int min_index = 0;
   for (int i = 1; i < 4; ++i) {
      if (rolls[i] < rolls[min_index])
         min_index = i;
   }
   int sum = 0;
   for (int i = 0; i < 4; ++i) {
      sum += rolls[i];
   }
   return sum - rolls[min_index];
}

int modifier(int score)
{
   return (int)floor((score - 10) / 2.);
}

dnd_character_t make_dnd_character(void)
{
   dnd_character_t character = { .charisma = ability(),
                                 .constitution = ability(),
                                 .dexterity = ability(),
                                 .intelligence = ability(),
                                 .strength = ability(),
                                 .wisdom = ability() };
   character.hitpoints = 10 + modifier(character.constitution);
   return character;
}
