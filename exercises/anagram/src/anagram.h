#ifndef ANAGRAM_H
#define ANAGRAM_H

enum anagram_status {
   UNCHECKED = -1,
   NOT_ANAGRAM,
   IS_ANAGRAM
};

struct candidate {
   enum anagram_status is_anagram;
   char *candidate;
};

struct candidates {
   struct candidate *candidate;
   size_t count;
};

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for word.  Word buffer and candidate structures may be modified.
 */
void anagrams_for(char word[], struct candidates *candidates);

#endif
