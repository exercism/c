# About

Dynamic memory is implemented by library functions which the programmer uses to allocate and deallocate memory at runtime.
Since the programmer controls the allocation and deallocation of memory, dynamic memory is as safe as the programmer is free from human error.
For that reason, dynamic memory is one of the  major sources for programming bugs and a major target for hacking attacks.
Given the riskiness of dynamic memory, a quick review of memory in general can be helpful to understanding why dynamic memory is needed.

## The four types of scope: block; function; function prototype; file

The scope of a value defines from where in the program that value an be accessed.

A value with block scope can only be accessed from within the block where it is defined.
A block is usually but not always defined within matching curly braces, such as those used for a function definition.
Examples of values with block scope are variables defined within function definitions, `if` statements or any of the loop statements.
As of C99, even if an `if` or loop statement uses no curly braces, a block exists within the statement.

Function scope is a special kind of scope that applies to labels used with `goto` statements.
Two labels with the same name cannot be used in the same function, even if the labels are defined in separate blocks in the function.

Function prototype scope is another special kind of scope that applies only to parameteres named within the protoype declaration.
A parameter name is usually optional in a function declaration.
A function definition does not have to use the same name for a parameter that was used in the function declaration.

A value with file scope can be accessed from anywhere in the file.

## The three types of linkage: external; internal; none

Linkage is a way of describing accessibility of a value from outside the file in which it is defined.
Values with block, function, or function prototype scope have no linkage.
This means they can't be accessed from outside their scope.

Values with file scope have external linkage by default.
A value with external linkage can be used from any file in the program.
To prevent this, a value with file scope can be made to have internal linkage by using the `static` specifier.
A value with internal linkage can only be used within its translation unit.
Its translation unit consists of its file and any other file its file `#include`s. 

For example

```c
int public_count = 0; // file scope, external linkage by default
static int private_count = 0;  // file scope, internal linkage 

int main()
{
    // code snipped
}
```

## The four types of storage durations: static; thread; automatic; allocated

The storage duration of a value refers to the lifetime of that value.

A value with `static` duration has a lifetime for the entire duration of the program.
Note that the keyword `static` has multiple meanings.
`static`, as a specifier for a value with file scope, defines it as having _internal linkage_.
A value with file scope always has a static _storage duration_, regardless of its linkage.
A value with block scope usually only has a lifetime for the duration of its block.
To allow a variable with block scope to live during the entire program, the variable can be given the `static` specifier.
The variable will have the same value when its block is re-entered as it had when its block was last exited.

The details of thread storage duration are beyond the scope of this article.
A simplified definition is that a value with thread storage duration lives for as long as its thread.

A value with automatic storage duration usually lives from the time the block in which it is defined is entered until that block is exited.
This means that the memory for a value with automatic storage duration is usually automatically allocated when the block is entered and is deallocated when the block is exited.

This example shows the difference between automatic and static lifetimes

```c
#include <stdio.h>

void my_function(void) {
    int short_lived_count = 0;
    static int long_lived_count = 0;
    printf("I've been called %d time(s) by short-lived count\n", ++short_lived_count);
    printf("I've been called %d time(s) by long-lived count\n", ++long_lived_count);  
}

int main() {
    
    // prints
    // I've been called 1 time(s) by short-lived count
    // I've been called 1 time(s) by long-lived count
    my_function();
    // prints
    // I've been called 1 time(s) by short-lived count
    // I've been called 2 time(s) by long-lived count
    my_function();
}
```

The examples we've seen have happened to use variables whose size is known at compile time.
Dynamic memory is used for variables whose size is only known at runtime.
This is commonly useful for arrays whose number of elements may vary between one runtime and the next.
Variable length arrays are another way to handle arrays whose element size is only known at runtime.
A detailed analysis of variable length arrays is outside the scope of this article.
VLAs were brought into the C language by C99, but as of C11 VLAs are optional, so compilers supporting C11 onward do not have to support VLAs.

## malloc

`malloc` is a function declared in `stdlib.h` which is used for allocating dynamic memory.
If the allocation is successful, a pointer is returned which points to the address of the first byte of the allocated memory.
If the allocation is not successful, `NULL` is returned.
It is prudent to check the result of `malloc` for `NULL` and gracefully handle it if it fails.
The pointer returned is of type `pointer-to-void` which can roughly be considered as a "generic" pointer that can be converted to the specific type used by the memory.
`malloc` has one parameter, which is the size of the desired memory in bytes.
The total size for allocating an array would be the size of each element's data type multiplied by the number of elements.
The `sizeof` operator is commonly used to get the size of each element's data type.
The following example demonstrates this

```c
#include <stdio.h>
#include <stdlib.h>

int * my_function(int count) {
    // pointer-to-void from malloc is converted to a pointer-to-int
    int * numbers = malloc(sizeof(int) * count);
    return numbers;
}

int main() {
    int * numbers = my_function(3);
    if (!numbers) return -1;
    // printed The size of numbers is 8 bytes (can vary by system)
    printf("The size of numbers is %zu bytes\n", sizeof(numbers));
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    // prints The first element of the array is 1
    printf("The first element of the array is %d\n", numbers[0]);
    // prints The second element of the array is 2
    printf("The second element of the array is %d\n", numbers[1]);
    // prints The third element of the array is 3
    printf("The third element of the array is %d\n", numbers[2]);
    free(numbers);
}
```

It's important to remember that the memory newly allocated by `malloc` is not initialized but may hold garbage values.
Note that the `sizeof` the `numbers` pointer is not the number of its array's elements, nor the total amount of memory allocated.
The size of the pointer returned by `malloc` is the size of any pointer on that particular system.
For the example the code was run on a 64-bit system, so the size of the pointer was 8 byes (multiplied by 8 bits per byte = 64 bits.)
The pointer type was converted from pointer-to-void to pointer-to-int.
Whether the pointer-to-int points to a single `int` or to an array of `ints` is something the programmer can deal with as seen fit.
For example

```c
#include <stdio.h>
#include <stdlib.h>

int * my_function(int count) {
    int * numbers = malloc(sizeof(int) * count);
    return numbers;
}

int main() {
    int * numbers = my_function(1);
    if (!numbers) return -1;
    // treat numbers as a single value
    *numbers = 1;
    // prints numbers is 1
    printf("numbers is %d\n", *numbers);
    // treat numbers as an array
    // prints The first element of the array is 1
    printf("The first element of the array is %d\n", numbers[0]);
    numbers[0] = 2;
    // prints The first element of the array is 2
    printf("The first element of the array is %d\n", numbers[0]);
    // treat numbers as a single value again
    // prints numbers is 2
    printf("numbers is %d\n", *numbers);    
    free(numbers);
}
```

## calloc

## realloc

## free
