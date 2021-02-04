#include "beer_song.h"
#include <stdio.h>
#include <string.h>

static unsigned int get_verse(unsigned int bottles, char *buffer)
{
   unsigned int bytes_written = 0;

   if (bottles == 0) {
      bytes_written =
          sprintf(buffer,
                  "No more bottles of beer on the wall, no more bottles of beer.\n"
                  "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
   } else if (bottles == 1) {
      bytes_written =
          sprintf(buffer,
                  "1 bottle of beer on the wall, 1 bottle of beer.\n"
                  "Take it down and pass it around, no more bottles of beer on the wall.\n");
   } else if (bottles == 2) {
      bytes_written =
          sprintf(buffer,
                  "2 bottles of beer on the wall, 2 bottles of beer.\n"
                  "Take one down and pass it around, 1 bottle of beer on the wall.\n");
   } else if (bottles <= 99) {
      bytes_written =
          sprintf(buffer,
                  "%u bottles of beer on the wall, %u bottles of beer.\n"
                  "Take one down and pass it around, %u bottles of beer on the wall.\n",
                  bottles, bottles, bottles - 1);
   }

   return bytes_written;
}

void recite(unsigned int start_bottles, unsigned int take_down, char *buffer)
{
   char *current_position = buffer;

   while (take_down-- > 0) {
      current_position += get_verse(start_bottles--, current_position);
      strcpy(current_position, "\n");
      current_position++;
   }

   strcpy(current_position - 1, "\0");
}
