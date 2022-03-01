## Introduction

A pointer is a variable or constant whose value is the address of another variable or constant.
Pointers are a powerful and potentially dangerous feature of C.
It can be challenging to understand pointers.

Variables and constants store their value in a memory location.
That location in memory is known as the address of the variable or constant.

To get the address of a variable we use the address operator, which is `&`.
```c
int i = 5;
int *i_address = &i;
```

A type followed by a `*` followed by an identifier is the way to declare a pointer to a variable of that type.
The `*` is known as the indirection operator because it indirectly refers to the value for which the pointer holds the address.

When we create an array like so

```c
int my_ints[] = {1, 2};
```

The value of `my_ints` is actually its address, which also happens to be the same as the address of its first element.
The address of its second element will be the first element's address plus the size of an `int` on the system.

This is why pointers are declared to be of a certain type.
If a pointer did not know what type it points to, it would not know how many bytes to advance when adding `1` to it.
Adding `1` to a pointer does not necessariy mean we're adding one byte to the address.
It means we're adding `1` times the length of its type in bytes.
