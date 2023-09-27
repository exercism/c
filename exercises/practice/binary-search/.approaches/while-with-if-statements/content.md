# `while` loop with `if` statements

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

This approach starts by checking for a `NULL` input array.
It then defines the [`size_t`][size_t] variables to keep track of the `left` and `right` positions being searched for in the array.
The `left` is initialized to `0` and the `right` is initialized to the length passed in.

The while loop will loop as long as the `left` position is less than the `right` position.

Inside the loop, the middle value is set by `left` plus ((`right` - `left`) divided by `2`).

- For example, if `left` is `0` and `right` is `10`, then the middle is calculated to `5`.
- If `left` is `6` and `right` is `10`, then the middle is calculated to `8`.

The reason for not doing (`left` + `right`) divided by `2` is to prevent overflow for very large sizes of the input array, as explained [here][mid-bug].

An `if` statement is used to check if the value in the array at the `mid` index is the value being searched for.
If so, then a pointer to that value is returned.

If the first `if` statement does not return, then another `if` statement is used to check the element.

~~~~exercism/note
Note that if an `if` statement can return, it does not need to be followed by an `else if ` or an `else`.
If the statement returns, then control flow will leave the function.
If the statement does not return, control will fall through to the next statement anyway.
~~~~

If the value at the middle index is less than the value being searched for, then `left` is set to the middle index
plus one so that the next iteration will look for higher numbers.

Otherwise, the value being searched for must be less than the value at the middle index, so `right` is set to the middle index
so that the next iteration will look at lower numbers.

If `left` and `right` are changed during the iterations so that `left` is no longer less than `right`,
then the value being searched for is not in the array of `int`s.
The loop exits and `NULL` is returned from the function.

[size_t]: https://en.cppreference.com/w/c/types/size_t
[mid-bug]: https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
