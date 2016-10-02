#include "beer_song.h"
#include <stdio.h>
#include <string.h>

static unsigned int getVerse(char *buffer, unsigned int verseNumber)
{
	unsigned int bytesWritten = 0;

	if (verseNumber == 0) {
		bytesWritten =
		    sprintf(buffer,
			    "No more bottles of beer on the wall, no more bottles of beer.\n"
			    "Go to the store and buy some more, 99 bottles of beer on the wall.\n");
	} else if (verseNumber == 1) {
		bytesWritten =
		    sprintf(buffer,
			    "1 bottle of beer on the wall, 1 bottle of beer.\n"
			    "Take it down and pass it around, no more bottles of beer on the wall.\n");
	} else if (verseNumber == 2) {
		bytesWritten =
		    sprintf(buffer,
			    "2 bottles of beer on the wall, 2 bottles of beer.\n"
			    "Take one down and pass it around, 1 bottle of beer on the wall.\n");
	} else if (verseNumber <= 99) {
		bytesWritten =
		    sprintf(buffer,
			    "%d bottles of beer on the wall, %d bottles of beer.\n"
			    "Take one down and pass it around, %d bottles of beer on the wall.\n",
			    verseNumber, verseNumber, verseNumber - 1);
	}

	return bytesWritten;
}

void verse(char *buffer, unsigned int verseNumber)
{
	(void)getVerse(buffer, verseNumber);
}

void sing(char *buffer, unsigned int startingVerseNumber,
	  unsigned int endingVerseNumber)
{
	char *currentPosition = buffer;

	for (unsigned int i = startingVerseNumber + 1; i > endingVerseNumber;
	     i--) {
		currentPosition += getVerse(currentPosition, i - 1);
		strcpy(currentPosition, "\n");
		currentPosition++;
	}

	strcpy(currentPosition - 1, "\0");
}
