#ifndef PALINDROME_H
#define PALINDROME_H

struct Paire
{
   int a;
   int b;
};

int isPalindrome(int a, int b);
Paire* palindromeFactors(int min, int max);

#endif
