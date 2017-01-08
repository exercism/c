#ifndef SERIES_H
#define SERIES_H

#define MAX_INPUT_TEXT_LENGTH (8)
#define MAX_SERIES_RESULTS (MAX_INPUT_TEXT_LENGTH)
#define MAX_SERIES_LENGTH (5)

// results structure
typedef struct SeriesResults {
   unsigned int substringCount;
   char **substring;            // array of pointers of dimension substringCount
} SeriesResults_t;

// series - routine to split up input text into consecutive substrings of text of a given substringLength
//
// inputs:
//    inputText - bounded to MAX_INPUT_TEXT_LENGTH
//    substringLength - the desired length of substrings that are returned bounded to MAX_SERIES_LENGTH
//
// outputs:
//    SeriesResult_t results - structure containing count of the substring and an array of
//       pointers to the substrings.
//
//       calling routine will free memory associated with each of the substrings and
//       the pointers to the substrings.
SeriesResults_t series(char *inputText, unsigned int substringLength);

#endif
