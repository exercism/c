# About

The scope of a value relates to where in the program that value can be accessed.

## The four types of scope: block; function; function prototype; file

A value with block scope can only be accessed from within the block where it is defined.
A block is usually but not always defined within matching curly braces, such as those used for a function definition.
Examples of values with block scope are variables defined within function definitions, `if` statements or any of the loop statements.
As of C99, even if an `if` or loop statement uses no curly braces, a block exists within the statement.
Also as of C99, values with block scope no longer have to be declared at the beginning of the block.

Function scope is a special kind of scope that applies to labels used with `goto` statements.
Two labels with the same name cannot be used in the same function, even if the labels are defined in separate blocks within the function.

Function prototype scope is another special kind of scope that applies only to parameters named within the protoype (also referred to as the declaration.)
A parameter name is usually optional in a function declaration.
The scope of a name is relevant only within the declaration.
In the following example the `len` identifier is defined and then referred to later in the function declaration.

```c
#include <stdio.h>

// len is defined and then referred to
void my_func(int len, int numbers[len]);

int main() {
    int numbers[2];
    numbers[0] = 1;
    numbers[1] = 2;
    my_func(2, numbers);
}

void my_func(int length, int numbers[length]) {
    // prints numbers should have 2 elements
    printf("numbers should have %d elements", length);
}
```

Note that within a declaration the names need to match up when referencing the same variable.
If `my_func` were declared as `void my_func(int len, int numbers[length]);` then a compile error would be generated something like

```
/tmp/scn62kKPEZ.c:4:35: error: 'length' undeclared here (not in a function)
    3 | void my_func(int len, int numbers[length]);
      |                                   ^~~~~~
/tmp/scn62kKPEZ.c: In function 'main':
/tmp/scn62kKPEZ.c:10:16: error: type of formal parameter 2 is incomplete
   10 |     my_func(2, numbers);
```

A function definition does not have to use the same name for a parameter that was used in the function declaration.
In the above example, `len` was used in the declaration and `length` was used in the definition, thus demonstrating that the scope of the `len` identifier was only within the function declaration.

A value with file scope can be accessed from anywhere in the file.
Any such a value is defined outside a function.
