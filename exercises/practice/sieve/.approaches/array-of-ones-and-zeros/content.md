# Array of ones and zeros

**sieve.h**

```c
#ifndef SIEVE_H
#define SIEVE_H

#include <stdint.h>
#include <stddef.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes);

#endif
```

**sieve.c**

```c
#include "sieve.h"

#define MAX_LEN 1001

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
   if (limit < 2 || max_primes == 0)
      return 0;

   uint32_t composite[MAX_LEN];
   for (int i = 0; i < MAX_LEN; i++)
      composite[i] = 0;

   size_t output_pos = 0;
   for (uint32_t number = 2; number <= limit; number++) {
      if (!composite[number]) {
         primes[output_pos++] = number;
         if (output_pos == max_primes)
            break;
         for (uint32_t idx = number * number; idx <= limit; idx += number)
            composite[idx] = 1;
      }
   }
   return (uint32_t)output_pos;
}
```

This approach starts by defining the `MAX_LEN` of the array of composite values to be `1001`,
given that the largest length for the result array expected by the tests is `1000`.

~~~~exercism/warning
It would be tempting to set the length of the composite array as a [Variable-length array](https://en.wikipedia.org/wiki/Variable-length_array)
dependent on the value of the `limit`, however, although VLAs were legal in C99, they were made optional in C11,
so compilers that support C11 and later are not required to implement VLAs.
~~~~

The `sieve` function starts by returning `0` if either the `limit` is too small to contain a prime,
or if the number of primes expected back is `0`.

The array of composite values is defined and then initialized with all zeros.

The index for the array of primes is set to `0`.

Since values less than `2` are not prime, the iteration of the `for` loop begins at 2.

If the number being iterated is not a composite number, then that number is set at the current index for the primes array.
`output_pos++` means that the value of `output_pos` is incremented _after_ it is used for indexing into the primes array.

If `output_pos` equals the maximum number or primes expected back, then the calcuating is done and [`break`][break] is used
to exit the `for` loop.
Otherwise, since any multiple of a prime number is not prime, the inner `for` loop iterates from the prime times itself,
setting each of the values at that index to `1` for being a composite number.

After the outer `for` loop is done, the array of primes is returned.

[VLA]: https://en.wikipedia.org/wiki/Variable-length_array
[break]: https://www.geeksforgeeks.org/c-break-statement/
