#ifndef PALINDROME_H
#define PALINDROME_H

/* structure containing the smallest and largest palindrome */
typedef struct {
   int small_palind;
   int larg_palind;
} Pair;

/* Return the smallest and biggest palindrome in the range of min and max */
Pair getPalindromeProduct(int min, int max);

#endif
