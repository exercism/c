#ifndef _WORD_COUNT_H
#define _WORD_COUNT_H


#define MAX_WORDS 20
#define MAX_WORD_LENGTH 50

typedef struct WordCount_Word {
   char text[MAX_WORD_LENGTH];
   int count;
}WordCount_Word_t;

// returns the number unique words that were counted...
int word_count(char *input_text, WordCount_Word_t words[MAX_WORDS]);

#endif
