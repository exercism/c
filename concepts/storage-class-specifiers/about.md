# About

Storage-class specifiers relate to how variables are stored in memory.
They are closely related to the storage duration (also referred to as the lifetime) of a value.

## auto (the default storage class for variables)

Since variables defined within a block or function are `auto` by default, it is not common to explicitly use the term.
Another reason that `auto` is often avoided is because it has a different meaning in C++.
Codebases that combine C and C++ may be less confusing by avoiding the `auto` storage specifier.
An `auto` variable's lifetime begins when its block is entered and ends when its block is exited.
An `auto` variable has memory allocated for it, _but with no default value_, when its block is entered.
An exception is for variable length arrays (VLAs.)
A VLA's allocation happens where it is declared or defined in its block and ends when its block is exited.
An `auto` variable can be initialized by any valid expression.


## static (the storage specifier not to be confused with the static linkage type)
A variable defined outside of a block or function has file scope and always has static storage duration.
File scope means it can be accessed anywhere in the file.
Static storage means it exists from the beginning of the program until the end.
Unless explicitly initialized, a static variable is initialized with its default zero value.
If a file scope variable is marked with `static`, the `static` refers to its linkage.
A file scope variable marked `static` has internal linkage, meaning it can only be accessed within the file.
If a variable is defined within a function or in a block within a function it has block scope.
Block scope means the variable can be accessed only in the block in which it was created.
A block scope variable marked `static` has static storage duration.
The `static` variable's value persists between calls to the function or block.

In the following example we see two static variables at work.
The first `count` variable is defined within the `print_stuff` function and retains its value between calls to the function.
The second `count` variable is defined within an arbitrary block and hides (or shadows) the first `count` variable within its block.
The second `count` variable independently retains its value between entries into the block.

```c
#include <stdio.h>

void print_stuff(void) {
    // static variable is initialized to 0
    static int count;
    count++;
    printf("function count is %d\n", count);
    {
        // static variable is initialized to 0
        static int count;
        count++;
        printf("block count is %d\n", count);
    }
}

int main() {
    // prints
    // function count is 1
    // block count is 1
    print_stuff();
    // prints
    // function count is 2
    // block count is 2    
    print_stuff();
}
```

If a `static` variable is explicitly initialized, it must be done so with a constant expression.
A constant expression is one which can be evaluated at compile time.

## extern (how not to shadow a variable in the enclosing scope)

TODO: Explain

```c
#include <stdio.h>

void set_val() {
    extern int val;
    val += 42;
    printf("val is %d\n", val);
}

int main() {
    set_val();
    extern int val;
    printf("val is %d\n", val);
}
// this value could be defined in another file.
// as a variable with static storage, it is initialized to zero
int val;
```

```c
#include <stdio.h>

void set_val() {
    // defined with static storage, but not in enclosing scope
    static int val;
    val += 42;
    printf("val is %d\n", val);
}

int main() {
    set_val();
    extern int val;
    printf("val is %d\n", val);
}
```

