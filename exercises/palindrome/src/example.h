#ifndef PALINDROME_H
#define PALINDROME_H

/* structure containing a pair of integer */
typedef struct paire {
   int a;
   int b;
} Paire;

/* structure containing a palindrome and an array of his factors */
typedef struct palindProduct {
   int palindrome;
   Paire *factors;
} PalindromeProduct;

/* Return 0 if the product of a and b is a palindrome, 1 otherwise */
int isPalindrome(int a, int b);

/* return the Paire of factors that give the palindrome ( see Paire) */
Paire *palindromeFactors(int palindrome);

/* Return the smallest and biggest palindrome in the range of min and max */
PalindromeProduct *getPalindromeProduct(int min, int max);

#endif
