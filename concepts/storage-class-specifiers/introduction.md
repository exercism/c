# Introduction

Storage-class specifiers relate to how variables are stored in memory.
They are closely related to the storage duration (also referred to as the lifetime) of a value.

## auto: the default storage class for function or block scope variables

Since variables defined within a block or function are `auto` by default, it is not common to explicitly use the term.
An `auto` variable's lifetime begins when its block is entered and ends when its block is exited.
An `auto` variable has memory allocated for it, _but with no default value_, when its block is entered.

## static: the storage specifier not to be confused with the static linkage type

If a variable is defined within a function or in a block within a function, it has block scope.
Block scope means the variable can be accessed only in the block in which it was created.
A block scope variable marked `static` has `static` storage duration.
The `static` variable's value persists between calls to the function or block.

## extern: how to access a variable in another translation unit

A translation unit consists of a source file and any other file it `#include`s.
Although a variable with file scope can be declared and initialized as `extern`, the `extern` keyword is usually used to refer to an existing variable, not to define a new one.
The variable referred to by `extern` must have file scope.
A variable in file scope always has `static` storage.
A variable in an included file must have external linkage to be accessed by the file including it.

## register: how to possibly speed access to a variable

A variable marked as `register` expresses the programmer's desire to have the value placed in a register for quick access.
A `register` variable is like an `auto` variable in that it must be in function or block scope.
Since the value is intended to be placed in a register instead of memory, accessing the address of the variable should be disallowed by the compiler, since the adress of a register can't be taken.
However, a memory address itself can be placed in a register.
`register` is essentially a hint, since the value may or may not be actually placed in a register.

## typedef: the storage class specifier that isn't really

`typedef` is described as a storage class specifier for syntactic reasons only.
This is because a storage class specifier can't be used with another storage class specifer.
So, `typedef auto int i = 42;` is just as illegal as `static auto int i = 42;`.
