#ifndef ANAGRAM_H
#define ANAGRAM_H

#define MAX_STR_LEN 20

struct Vector {
   char (*vec)[MAX_STR_LEN];
   int size;
};

struct Vector anagrams_for(char *, struct Vector);

#endif
