# Introduction

There are several ways to solve Armstrong Numbers.
One approach can use [`log10`][log10] to get the number of digits, and it can avoid the use of [`pow`][pow].
The `pow` function is convenient, but it may be called many times, and it converts the `int` input to `double`,
and returns a `double` to be converted back to an `int`, so it is less efficient than manually multiplying the number.

## Approach: `log10` with no `pow`

**armstrong_numbers.h**

```c
#ifndef ARMSTRONG_NUMBERS
#define ARMSTRONG_NUMBERS
#include <stdbool.h>

bool is_armstrong_number(int candidate);

#endif
```

**armstrong_numbers.c**

```c
#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate)
{
    if (candidate < 10)
        return true;

    int digit_count = log10(candidate) + 1;

    int num = candidate;
    int pow_total = 0;
    while (num > 0)
    {
        int pow_temp = num % 10;
        int pow_temp_total = 1;
        for (int i = 0; i < digit_count; i++)
            pow_temp_total *= pow_temp;
        pow_total += pow_temp_total;
        num /= 10;
    }
    return candidate == pow_total;
}
```

For more information, check the [`log10` with no `pow` approach][approach-log10-no-pow].

[approach-log10-no-pow]: https://exercism.org/tracks/c/exercises/armstrong-numbers/approaches/log10-no-pow

[log10]: https://www.tutorialspoint.com/c_standard_library/c_function_log10.htm
[pow]: https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm
