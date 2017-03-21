#ifndef PALINDROME_H
#define PALINDROME_H

/* structure containing a pair of integer */
typedef struct pair {
   int a;
   int b;
} Pair;

/* structure containing a palindrome and an array of his factors */
typedef struct palindProduct {
   int palindrome;
   Pair *factors;
} PalindromeProduct;

/* Return the smallest and biggest palindrome in the range of min and max */
PalindromeProduct *getPalindromeProduct(int min, int max);

#endif
