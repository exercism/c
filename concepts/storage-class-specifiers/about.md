# About

Storage-class specifiers relate to how variables are stored in memory.
They are closely related to the storage duration (also referred to as the lifetime) of a value.

## auto: the default storage class for function or block scope variables

Since variables defined within a block or function are `auto` by default, it is not common to explicitly use the term.
Another reason that `auto` is often avoided is because it has a different meaning in C++.
Codebases that combine C and C++ may be less confusing by avoiding the `auto` storage specifier.
An `auto` variable's lifetime begins when its block is entered and ends when its block is exited.
An `auto` variable has memory allocated for it, _but with no default value_, when its block is entered.
An exception is for variable length arrays (VLAs.)
A VLA's allocation happens where it is declared or defined in its block and ends when its block is exited.
An `auto` variable can be initialized by any valid expression.

## static: the storage specifier not to be confused with the static linkage type

A variable defined outside of a block or function has file scope and always has static storage duration.
File scope means it can be accessed anywhere in the file.
Static storage means it exists from the beginning of the programs execution until the end.
Unless explicitly initialized, a `static` variable is initialized with its default zero value.
If a file scope variable is marked with `static`, the `static` refers to its linkage.
A file scope variable marked `static` has internal linkage, meaning it can only be accessed within the file.
If a variable is defined within a function or in a block within a function, it has block scope.
Block scope means the variable can be accessed only in the block in which it was created.
A block scope variable marked `static` has `static` storage duration.
The `static` variable's value persists between calls to the function or block.

In the following example we see two `static` variables at work.
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

## extern: how to access a variable in another translation unit

A translation unit consists of a source file and any other file it `#include`s.
Although a variable with file scope can be declared and initialized as `extern`, the `extern` keyword is usually used to refer to an existing variable, not to define a new one.
The variable referred to by `extern` must have file scope.
A variable in file scope always has `static` storage.
A variable in an included file must have external linkage to be accessed by the file including it.

In the following example we use the variable `val` declared as `extern` so that it will refer to `val` defined in its file scope.
Both uses of `extern` are called referencing declarations, since they reference a variable defined elsewhere.

```c
#include <stdio.h>

void set_val() {
    // this declares val which is defined elsewhere
    extern int val;
    val += 42;
    // prints val is 42
    printf("val is %d\n", val);
}

int main() {
    set_val();
    // this declares val which is defined elsewhere
    extern int val;
    val += 42;
    // prints val is 84
    printf("val is %d\n", val);
}
// this value could be defined in another source file.
// as a variable with static storage, it is initialized to zero
int val;
```

If both `extern` keywords were removed the program might print something like

```
val is 22038
val is 42
```

Such an output demonstrates that each declaration of `val` without `extern` is a defining declaration and is independent of the other declarations of `val`.
Entirely removing the declarations of `val` from `set_val` and `main` would result in a compile error that `val` is undeclared in `set_val` and `main`.

If a variable referred to as `extern` is in the same file, it can have either internal or external linkage.
Defining `val` as `static int val;` would have no effect on the use of `val` in `set_val` or `main`, except that the definition would need to be moved above them to compile.
But if `val` were defined above the functions they would not need to declare `val` as `extern`.

The following would work

```c
#include <stdio.h>

// val defining declaration before the function definitions
static int val;

void set_val() {
    val += 42;
    // prints val is 42
    printf("val is %d\n", val);
}

int main() {
    set_val();
    val += 42;
    // prints val is 84
    printf("val is %d\n", val);
}
```

The `static` could be removed from `static int val;`, giving `val` external linkage,  and `val` would still work the same in `set_val` and `main`.
If another source file included this file, it could only use `val` if `val` had external linkage (not declared as `static`) and the other file declared `extern int val;`.

A variable referred to by `extern` must not only have `static` storage, but must also have file scope.
The following example will most likely not compile, because `val`, though `static`, does not have file scope.

```c
#include <stdio.h>

void set_val() {
    // defined with static storage, but not in file scope
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

## register: how to possibly speed access to a variable

A variable marked as `register` expresses the programmer's desire to have the value placed in a register for quick access.
A `register` variable is like an `auto` variable in that it must be in function or block scope.
Since the value is intended to be placed in a register instead of memory, accessing the address of the variable should be disallowed by the compiler, since the address of a register can't be taken.
However, a memory address itself can be placed in a register.
The following example demonstrates that

```c
#include <stdio.h>

int main() {
    int i = 42;
    register int *i_ptr = &i;
    // prints i is 42, i_ptr is 0x7ffd0c2055c4 (or some other address)
    printf("i is %d, i_ptr is %p", i, i_ptr);
}
```

register` is essentially a hint, since compilers are free to chose if they follow this specifier or not, so the value may or may not be actually placed in a register.

## typedef: the storage class specifier that isn't really

`typedef` is described as a storage class specifier for syntactic reasons only.
This is because a storage class specifier can't be used with another storage class specifer.
So, `typedef auto int i = 42;` is just as illegal as `static auto int i = 42;`.
