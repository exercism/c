# Introduction

There are several ways to solve Difference of Squares.
One approach is to use a [formula][formula]  instead of looping to calculate the solution.

## Approach: Use formula

**difference_of_squares.h**

```c
#ifndef DIFFERENCE_OF_SQUARES_H
#define DIFFERENCE_OF_SQUARES_H

unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);

#endif
```

**difference_of_squares.c**

```c
#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int number)
{
   unsigned int sum = (number * (number + 1)) / 2;
   return sum * sum;
}

unsigned int sum_of_squares(unsigned int number)
{
   return (number * (number + 1) * ((number * 2) + 1)) / 6;
}

unsigned int difference_of_squares(unsigned int number)
{
   return square_of_sum(number) - sum_of_squares(number);
}
```

For more information, check the [formula approach][approach-formula].

[formula]: https://learnersbucket.com/examples/algorithms/difference-between-square-of-sum-of-numbers-and-sum-of-square-of-numbers/
[approach-formula]: https://exercism.org/tracks/c/exercises/difference-of-squares/approaches/formula
