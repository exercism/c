#ifndef PALINDROME_PRODUCTS_H
#define PALINDROME_PRODUCTS_H

typedef struct {
   int small_palind;
   int larg_palind;
} Pair;

/* Return the smallest and biggest palindrome in the range of min and max */
Pair getPalindromeProduct(int min, int max);

#endif
