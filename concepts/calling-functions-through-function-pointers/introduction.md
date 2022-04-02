# Introduction

Just as a pointer can be made to an `int` or other basic data type, a pointer can be made to a function.
A function pointer can be used to pass a function to another function.
A function which is passed as a parameter value to another function is known as a first class function.
A function which takes one or more functions as a parameter, or which returns a function, is known as a higher order function.

In the following example, `is_even` and `is_odd` are first class functions.
The higher order function is `test_number`.

```c
#include <stdio.h>
#include <stdbool.h>

bool is_even (int number) {
    return number & 1 != 1;
}

bool is_odd (int number) {
    return number & 1 == 1;
}

// this function takes any other function which takes a number and returns a bool
void test_number(bool (*func) (int), int number, char *text){
    printf(text, number, func(number)? "true": "false");
}

int main() {
    // prints Testing odd for 3 is true
    test_number(is_odd, 3,"Testing odd for %d is %s\n");
    // prints Testing even for 3 is false
    test_number(is_even, 3,"Testing even for %d is %s\n");
}
```
The function signature of `bool (*func) (int)` for the first argument to `test_number` matches the signature of the functions passed in.
Both `is_even` and `is_odd` take an `int` parameter and return a `bool`.
In `(*func)`, `func` represents the name of the function to be used.
if `(*fn)` were used, then it would have been called like so: `printf(text, number, fn(number)? "true": "false");`.
To satisfy the function pointer parameter, we pass the name of a function having the expected signature when calling `test_number`.
Thus, we see that a function name points to the address of that named function.
