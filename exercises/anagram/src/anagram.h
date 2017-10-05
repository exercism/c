#ifndef ANAGRAM_H
#define ANAGRAM_H

#define MAX_STR_LEN 20

struct vector {
   char (*vec)[MAX_STR_LEN];
   int size;
};

struct vector anagrams_for(char *, struct vector);

#endif
