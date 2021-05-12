#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>

static uint16_t get_verse(uint8_t bottles, char **verse)
{
   uint16_t lines_written = 0;

   if (bottles == 0) {
      sprintf(*verse, "No more bottles of beer on the wall, no more bottles of beer.");
      sprintf(*++verse, "Go to the store and buy some more, 99 bottles of beer on the wall.");
      lines_written = 2;
   } else if (bottles == 1) {
      sprintf(*verse, "%u bottle of beer on the wall, %u bottle of beer.", bottles, bottles);
      sprintf(*++verse, "Take it down and pass it around, no more bottles of beer on the wall.");
      lines_written = 3;
   } else {
      sprintf(*verse, "%u bottles of beer on the wall, %u bottles of beer.", bottles, bottles);
      sprintf(*++verse, "Take one down and pass it around, %u bottle%sof beer on the wall.", bottles - 1, bottles - 1 == 1 ? " " : "s ");
      lines_written = 3;
   }

   return lines_written;
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
   while (take_down-- > 0) {
      song += get_verse(start_bottles--, song);
   }
}
