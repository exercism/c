#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#define MAX_WORDS 20            // at most MAX_WORDS will be found in the test input string
#define MAX_WORD_LENGTH 50      // no individual word will exceed this length

// results structure
typedef struct WordCount_Word {
   char text[MAX_WORD_LENGTH];
   int count;
} WordCount_Word_t;

// word_count - routine to classify the unique words and their frequency in a test input string
// inputs:
//    input_text =  string no longer than will take (MAX_WORDS * MAX_WORD_LENGTH)
//    words = allocated structure to record the words fourn and their frequency
//
// outputs:
//    uniqueWords - number of words in the words structure
int word_count(char *input_text, WordCount_Word_t words[MAX_WORDS]);

#endif
