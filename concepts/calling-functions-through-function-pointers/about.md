# About

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

The following example compiles but crashes when calling a function without the expected signature

```c
#include <stdio.h>
#include <stdbool.h>

bool is_even (int number) {
    return number & 1 != 1;
}

bool is_odd (int number) {
    return number & 1 == 1;
}

void is_zero(int number, char *text) {
    printf(text, number, number == 0? "true": "false");
}

void test_number(bool (*func) (int), int number, char * text){
    printf(text, number, func(number)? "true": "false");
}

int main() {
    // prints Testing odd for 3 is true
    test_number(is_odd, 3,"Testing odd for %d is %s\n");
    // prints Testing even for 3 is false
    test_number(is_even, 3,"Testing even for %d is %s\n");
    // program crashes. May report segmentation fault.
    test_number(is_zero, 3,"Testing zero for %d is %s\n");
}
```

One platform reported a segmentation fault.
Another gave warning

```
'void (__cdecl *)(int,char *)' differs in parameter lists from 'bool (__cdecl *)(int)'
'function': incompatible types - from 'void (__cdecl *)(int,char *)' to 'bool (__cdecl *)(int)'
```

For the second platform, the warning did not prevent compilation and the program still crashed when calling a function with the wrong signature to `test_number`.

The following example shows what happens when `test_number` keeps its signature but has its implementation changed to handle `is_zero`.

```c
#include <stdio.h>
#include <stdbool.h>

void is_zero(int number, char *text) {
    printf(text, number, number == 0? "true": "false");
}

void test_number(bool (*func) (int), int number, char * text){
    // func does not have the expected signature, but we call it correctly
    func(number, text);
}

int main() {
    // one platform doesn't compile. Another platform compiles with warnings and prints
    // Testing zero for 3 is false
    test_number(is_zero, 3,"Testing zero for %d is %s\n");
}
```

One platform did not compile with the following errors

```
In function 'test_number':
/tmp/7WSD1Rhh5e.c: error: too many arguments to function 'func'
   18 |     func(number, text);
      |     ^~~~
/tmp/7WSD1Rhh5e.c: In function 'main':
/tmp/7WSD1Rhh5e.c:: warning: passing argument 1 of 'test_number' from incompatible pointer type [-Wincompatible-pointer-types]
      |     test_number(is_zero, 3,"Testing zero for %d is %s\n");
      |                 ^~~~~~~
      |                 |
      |                 void (*)(int,  char *)
/tmp/7WSD1Rhh5e.c: note: expected '_Bool (*)(int)' but argument is of type 'void (*)(int,  char *)'
      | void test_number(bool (*func) (int), int number, char * text){
```

Another platform compiled with the following warnings

```
'func': too many actual parameters
'void (__cdecl *)(int,char *)' differs in parameter lists from 'bool (__cdecl *)(int)'
'function': incompatible types - from 'void (__cdecl *)(int,char *)' to 'bool (__cdecl *)(int)'
```

For the second platform, since the implementation of `test_number` changed to handle the signature of `is_zero`, it executed without crashing.

When we see that the same code can result in different results on different platforms we can infer that calling a function pointer with the wrong signature results in undefined behavior (UB.)

The following example shows what happens when we pass a function with the wrong signature but don't call it.

```c
#include <stdio.h>
#include <stdbool.h>

void is_zero(int number, char *text) {
    printf(text, number, number == 0? "true": "false");
}

void test_number(bool (*func) (int), int number, char * text){
    // passed a function without the expected signature, but we don't call it.
    // One platform does not create the executable, but without errors or warnings.
    // Another platform compiles, and when run prints Everything okay
    printf("Everything okay");
}

int main() {
    number(is_zero, 3,"Testing zero for %d is %s\n");
}
```

From the differing results on the two platforms we see that just passing a function pointer of the wrong signature can result in undefined behavior, even if that function is not called.
