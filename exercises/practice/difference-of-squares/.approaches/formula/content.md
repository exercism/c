# Use formula

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

In this solution a [formula][formula] is used to solve the `square_of_sum` and `sum_of_squares` functions.

At the time of this writing the instructions state:

>You are not expected to discover an efficient solution to this yourself from first principles; 
>research is allowed, indeed, encouraged.
>Finding the best algorithm for the problem is a key skill in software engineering.

It is fine to search for an algorithm on the internet.
This is also sometimes referred to as ["Google is your friend"][google-friend], although you don't have to search with Google.

It is okay if you don't understand how the algorithm works.
What is important is that it obviously is not introducing malware and that it passes the tests.

Note that this avoids using [`pow`][pow] in `square_of_sum`,
since multiplying a value by itself is usually more efficient than type-casting from `int `to `double` back to `int`.

[formula]: https://learnersbucket.com/examples/algorithms/difference-between-square-of-sum-of-numbers-and-sum-of-square-of-numbers/
[google-friend]: https://en.wiktionary.org/wiki/Google_is_your_friend
[pow]: https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm
