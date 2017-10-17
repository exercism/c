# C Style Guide

This guide describes the style intended for use with the C track exercise example 
and test files.

The rules within this guide are in addition to, or to call out, those in the 
[Linux kernal coding style guide](https://www.kernel.org/doc/html/latest/process/coding-style.html).

## Names

In general names of types, variables, structures and files should use all 
lower-case snake case, where underscores `_` are used to separate name 
components.

```c
void some_foo_function(char * input_string, int input_string_length);
```

## Enums

Enum names should usually be singluare rather than plural.

Enum labels should be capitalized.

```c
enum heading {
    HEADING_NORTH,
    HEADING_EAST,
    HEADING_SOUTH,
    HEADING_WEST
}
```

## Macro names

Macros defining constants are capitalized.

```c
#define CONSTANT 0x4000
```

Capitalized macro names are appreciated, but macros resembling functions may be
named in lower case.

## Constant names

Names for variables defined as `const` should be capitalized.

```c
const int LIMIT = 22;
```


## Type Names

Types defined by a program using `typedef` should have a `_t` suffix. While aware 
that POSIX reserves the `_t` suffix, the track does not currently utilise POSIX.
