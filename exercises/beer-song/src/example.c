#include "beer_song.h"
#include <stdio.h>
#include <string.h>

static unsigned int get_verse(char *buffer, unsigned int verse_number)
{
   unsigned int bytes_written = 0;

   if (verse_number == 0) {
      bytes_written =
          sprintf(buffer,
                  "No more bottles of beer on the wall, no more bottles of beer.\n"
                  "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
   } else if (verse_number == 1) {
      bytes_written =
          sprintf(buffer,
                  "1 bottle of beer on the wall, 1 bottle of beer.\n"
                  "Take it down and pass it around, no more bottles of beer on the wall.\n");
   } else if (verse_number == 2) {
      bytes_written =
          sprintf(buffer,
                  "2 bottles of beer on the wall, 2 bottles of beer.\n"
                  "Take one down and pass it around, 1 bottle of beer on the wall.\n");
   } else if (verse_number <= 99) {
      bytes_written =
          sprintf(buffer,
                  "%u bottles of beer on the wall, %u bottles of beer.\n"
                  "Take one down and pass it around, %u bottles of beer on the wall.\n",
                  verse_number, verse_number, verse_number - 1);
   }

   return bytes_written;
}

void verse(char *buffer, unsigned int verse_number)
{
   (void)get_verse(buffer, verse_number);
}

void sing(char *buffer, unsigned int starting_verse_number,
          unsigned int ending_verse_number)
{
   char *current_position = buffer;

   for (unsigned int i = starting_verse_number + 1; i > ending_verse_number;
        i--) {
      current_position += get_verse(current_position, i - 1);
      strcpy(current_position, "\n");
      current_position++;
   }

   strcpy(current_position - 1, "\0");
}
