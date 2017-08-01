#ifndef PERFECT_NUMBERS_H
#define PERFECT_NUMBERS_H

typedef enum {
   perfect_number = 1,
   abundant_number = 2,
   deficient_number = 3,
   error = -1
} kind;

kind classify_number(int);

#endif
