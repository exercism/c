#ifndef ANAGRAM_H
#define ANAGRAM_H

enum anagramStatus {
   UNCHECKED = -1,
   NOT_ANAGRAM,
   IS_ANAGRAM
};

struct candidate {
   enum anagramStatus isAnagram;
   char *candidate;
};

struct candidates {
   struct candidate *candidate;
   int size;
};
/**
 * @description - determines if any of the words in candidate are anagrams
 *                for word.  Word buffer and candidate structures may be modified.
 *
 * @param - word, buffer containing a word used to look for an anagram in  candidates.
 *          may be modified before function returns.
 *
 * @param - candidates, list of potential anagrams as an array of struct candidate.
 *          Words in candidate structure may be modifies before function returns.
 *          candidate.isAnagram will be set to IS_ANAGRAM if the candidate is an
 *          anagram for word.
 */
void anagrams_for(char word[], struct candidates *candidates);

#endif
