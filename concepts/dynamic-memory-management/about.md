# About

Dynamic memory is implemented by library functions which the programmer uses to allocate and deallocate memory at runtime.
Since the programmer controls the allocation and deallocation of memory, dynamic memory is as safe as the programmer is free from human error.
For that reason, dynamic memory is one of the  major sources for programming bugs and a major target for hacking attacks.

Dynamic memory is used for variables whose size is only known at runtime.
This is commonly useful for arrays whose number of elements may vary between one runtime and the next.
Variable length arrays (VLA) are another way to handle arrays whose element size is known only at runtime.
A VLA uses automatic storage, which means its memory is destroyed on leaving its defining block.
(For more on storage, please see the [storage class specifiers](https://github.com/exercism/c/tree/main/concepts/storage-class-specifiers) concept.)
VLAs were brought into the C language by C99, but as of C11 VLAs are optional, so compilers supporting C11 onward do not have to support VLAs.
A detailed analysis of variable length arrays is outside the scope of this article.

## malloc

`malloc` is a function declared in `stdlib.h` which is used for allocating dynamic memory.
If the allocation is successful, a pointer is returned which points to the address of the first byte of the allocated memory.
If the allocation is not successful, `NULL` is returned.
It is prudent to check the result of `malloc` for `NULL` and gracefully handle it if it fails.
The pointer returned is of type `pointer-to-void` which can roughly be considered as a "generic" pointer that can be converted to the specific type used by the memory.
`malloc` has one parameter, which is the size of the desired memory in bytes.
The total size for allocating an array is the size of each element's data type multiplied by the number of elements.
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
    numbers = NULL;
}
```

It's important to remember that the memory newly allocated by `malloc` is not initialized but may hold garbage values.
Note that the `sizeof` the `numbers` pointer is not the number of the array's elements, nor the total amount of memory allocated.
The size of the pointer returned by `malloc` is the size of any pointer on that particular system.
The example code was run on a 64-bit system, so the size of the pointer was 8 byes (multiplied by 8 bits per byte = 64 bits.)
The pointer type was implicitly converted from pointer-to-void to pointer-to-int.
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
    numbers = NULL;    
}
```

If the value(s) will definitely be written to before being read, then to use `malloc` can be an efficient way to allocate memory.
But, if there is a chance the value(s) will be read before being intialized, then to use `malloc` is risky.
A safer way to allocate memory is to use `calloc`, which initializes the newly allocated memory to zero.

Note in the examples above that `free(numbers)` was used.

## free

`free` is a function declared in `stdlib.h` which is used for deallocating memory which has been dynamically allocated.
Dynamically allocated memory stays claimed in memory until released by `free`.
Some operating systems may automatically free dynamically allocated memory when the program finishes, but it is best practice not to depend on that.
`free` has one parameter, which is a pointer to the memory which was dynamically allocated.
The use or lack of use of `free` is associated with several memory issues.

#### memory leak

Not freeing dynamically allocated memory after the reference to that memory reaches the end of its lifetime, or is otherwise destroyed, is referred to as a memory leak.
Leaked memory is memory which is claimed by the system but is no longer accessible by the program.
This can be a particular problem if memory is allocated in a loop, not freed at the end of the loop, and allocated again at the beginning of the loop.
If enough memory is allocated without being freed, the call to allocate memory will fail due to insufficient memory remaining to allocate.
It's important to remember that, although dynamically allocated memory is claimed by the system until freed, the pointer it is assigned to may only have block scope.
For instance, in the `malloc` examples, memory is allocated in `my_function`.
That memory would be leaked if the pointer to it were not returned and used to set the `numbers` pointer in `main`.
Thus, passing that `numbers` pointer to `free` releases the memory allocated in `my_function`.

#### use after free (**UAF**)

If memory is accessed after it is freed, the value(s) could be anything.
In the following example, the memory pointed to by `numbers` is freed and then is read from in `printf`.

```c
#include <stdio.h>
#include <stdlib.h>

int * my_function(int count) {
    // pointer-to-void from malloc is converted to a pointer-to-int
    int * numbers = (int *) malloc(sizeof(int) * count);
    return numbers;
}

int main() {
    int * numbers = my_function(1);
    if (!numbers) return -1;
    *numbers = 1;
    // prints numbers is 1
    printf("numbers is %d\n", *numbers);
    free(numbers);
    // could  print anything, e.g.
    // The first element of the array is 18178656
    printf("The first element of the array is %d\n", numbers[0]);
}
```

The `numbers` pointer, after it has been freed, is referred to as a dangling pointer.
A dangling pointer can refer to other memory than that for which it was intended.
Thus, a dangling pointer can lead to data corruption and arbitrary code substitution and execution.
A pointer to allocated memory which has not been cleared by setting to `NULL` can be used to hack the program.
In the above example, if `numbers` was set to `NULL` like so: `numbers = NULL;` after being freed, the following `printf` would result in program termination, perhaps reporting a segmentation fault when attempting to read `numbers[0]`.

#### double free

If `free` is called twice on a pointer to dynamically allocated memory, it results in undefined behavior (**UB**.)
This means the compiler can arbitrarily handle it any way it wants to.
The following example, compiled with two different compilers, can have two different outcomes

```c
#include <stdio.h>
#include <stdlib.h>

int * my_function(int count) {
    // pointer-to-void from malloc is converted to a pointer-to-int
    int * numbers = (int *) malloc(sizeof(int) * count);
    return numbers;
}

int main() {
    int * numbers = my_function(1);
    if (!numbers) return -1;
    *numbers = 1;
    // prints numbers is 1
    printf("numbers is %d\n", *numbers);
    free(numbers);
    // numbers = NULL;
    // first compiler generates runtime error: double free detected in tcache 2
    // second compiler generates no error
    free(numbers);
}
```

The first and second compiler generated no runtime error when `numbers` was set to `NULL` between each call to `free`, but that would not be guaranteed to work with a third compiler.
A common source of double free is to have two pointers which point at the same dynamically allocated memory.
One pointer may point at the beginning of an array at one place in the program, and the other pointer may be used to step though the array at another place in the program.
At different places in the program, each pointer is freed, thus causing a double free.

## calloc

`calloc` is a function declared in `stdlib.h` which is used for both allocating dynamic memory and initializing the newly allocated memory to zero.
If the allocation is successful, a pointer is returned which points to the address of the first byte of the allocated memory.
If the allocation is not successful, `NULL` is returned.
It is prudent to check the result of `calloc` for `NULL` and gracefully handle it if it fails.
The pointer returned is of type `pointer-to-void` which can roughly be considered as a "generic" pointer that can be converted to the specific type used by the memory.
`calloc` has two parameters.
The first parameter is for how many of the specified data type is to be allocated.
The second parameter is for the size of the specified data type to be allocated.

In the following example all of the `printf` statements should always show `0`, since `calloc` is guaranteed to zero the newly allocated values.

```c
#include <stdio.h>
#include <stdlib.h>

int * my_function(int count) {
    // allocates the amount of bytes in an int, multiplied by count
    int * numbers = calloc(count, sizeof(int));
    return numbers;
}

int main() {
    int * numbers = my_function(3);
    if (!numbers) return -1;
    // prints The first element of the array is 0
    printf("The first element of the array is %d\n", numbers[0]);
    // prints The second element of the array is 0
    printf("The second element of the array is %d\n", numbers[1]);
    // prints The third element of the array is 0
    printf("The third element of the array is %d\n", numbers[2]);
    free(numbers);
    numbers = NULL;
}
```

## realloc

`realloc` is a function declared in `stdlib.h` which is used for either expanding or shrinking existing allocated memory.
If the reallocation is successful, a pointer is returned which points to the address of the first byte of the reallocated memory.
If the reallocation is not successful, `NULL` is returned.
It is prudent to check the result of `realloc` for `NULL` and gracefully handle it if it fails.
`realloc` has two parameters.
The first parameter is a pointer to the existing memory to be reallocated.
The second parameter is for the size in bytes of the reallocated memory.
Values that were set before memory is expanded are retained.
It is important to remember that memory added when expanding memory is not initialized to zero and its value(s) could be anything.
Also, memory which is removed when shrinking memory is also not initialized and could retain the value(s).
The following example demonstrates expanding and shrinking an array

```c
#include <stdio.h>
#include <stdlib.h>

int * my_function(int count) {
    // allocates the amount of bytes in an int, multiplied by count
    int * numbers = calloc(count, sizeof(int));
    return numbers;
}

int * my_function_2 (int * ptr , int count) {
    // reallocates the memory to the size of an int multiplied by count
    int * numbers = realloc(ptr, sizeof(int) * count);
    // if realloc fails, exit the program
    if (!numbers) exit(-1);
    return numbers;
}

int main() {
    int * numbers = my_function(3);
    if (!numbers) return -1;
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    // expand the size of the array
    numbers = my_function_2(numbers, 6);
    // prints The first element of the array is 1
    printf("The first element of the array is %d\n", numbers[0]);
    // prints The sixth element of the array is [whatever is there]
    // the additional memory is not initialized, so it could be
    // 0 or it could be 18728 or anything else
    printf("The sixth element of the array is %d\n", numbers[5]);
    numbers[5] = 6;
    // shrink the size of the array
    numbers = my_function_2(numbers, 3);
    // prints The sixth element of the array is [whatever is there]
    // the removed memory is not initialized, so it could be
    // 6 or it could be 43164 or anything else
    printf("The sixth element of the array is %d\n", numbers[5]);
    free(numbers);
}
```

## When the size passed is 0

If the size passed to `malloc`, `calloc`, or `relloac` is `0`, then what happens depends on how the compiler implements it.
A compiler may either return a `NULL` pointer or a non-null pointer.
For example, if allocating memory for a pointer to `char`, the compiler may return either `NULL` or a non-null pointer to an empty string.
To avoid differing results with differing compilers it is best to not allocate with a size of 0.
