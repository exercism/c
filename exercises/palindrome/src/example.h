#ifndef PALINDROME_H
#define PALINDROME_H

typedef struct paire
{
   int a;
   int b;
} Paire;

int isPalindrome(int a, int b);
Paire* palindromeFactors(int min, int max);

#endif
