#ifndef SERIES_H
#define SERIES_H

#define MAX_INPUT_TEXT_LENGTH (8)
#define MAX_SERIES_RESULTS (MAX_INPUT_TEXT_LENGTH)
#define MAX_SERIES_LENGTH (5)

// results structure
typedef struct slices {
   unsigned int substring_count;
   char **substring;   // array of pointers of dimension substring_count
} slices_t;

// slices - routine to slice up input text into consecutive substrings of text
// of a given substring_length
//
// inputs:
//    input_text - bounded to MAX_INPUT_TEXT_LENGTH
//    substring_length - the desired length of substrings that are returned
//    bounded to MAX_SERIES_LENGTH
//
// outputs:
//    slices_t results - structure containing count of the substrings and an
//    array of
//       pointers to the substrings.
//
//       Calling routine will free memory associated with each of the substrings
//       and the pointers to the substrings.
slices_t slices(char *input_text, unsigned int substring_length);

#endif
