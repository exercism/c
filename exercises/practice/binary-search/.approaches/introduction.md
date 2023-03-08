# Introduction

There are many ways to solve Binary Search.
One approach can use a `while` loop with `if` statements.

## Approach: `while` loop with `if` statements

**binary_search.h**

```c
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

int* binary_search(int value, const int *arr, size_t length);

#endif
```

**binary_search.c**

```c
#include "binary_search.h" 

int* binary_search(int value, const int *arr, size_t length){
    if (!arr) return NULL;
    size_t left = 0, right = length;
    while (left < right) {
        size_t mid = left + ((right - left) / 2);
        int look = arr[mid];
        if (look == value) return (int *) &arr[mid];
        if (look < value) left = mid + 1;
        else right = mid;
    }
    return NULL;
}
```

For more information, check the [`while` loop with `if` statements approach][approach-while-with-if-statements].

[approach-while-with-if-statements]: https://exercism.org/tracks/c/exercises/binary-search/approaches/while-with-if-statements
