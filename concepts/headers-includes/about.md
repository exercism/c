# About

C requires that all functions are declared _before_ they are defined.
This can be done at the top of the `*.c` file containing the definition, but there are advantages in splitting declarations into a separate header file with a `.h` extension.

You can think of the header file as an API.
The header will tell you _what_ a codebase has to offer, without going into the details of _how_.

## Header files

A header file can range from just a few lines to several hundred.

For a simple example, we can look at the `Hello World` exercise (which you already completed). This is the [`hello_world.h` file][hello-h] which is part of that exercise:

```c
// This is called an include guard, which ensures that the header is only
// included once. You could alternatively use '#pragma once'. See
// https://en.wikipedia.org/wiki/Include_guard.
#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

// Declare the 'hello()' function, which takes no arguments and returns a
// 'const char *', i.e. a pointer to a character (in this case the first
// character in a string). The function itself is defined in the hello_world.c
// source file. This function is called by the test case(s) in the test source
// file test_hello_world.c.
const char *hello(void);

#endif
```

Most of it is explanatory comments (lines starting with `//`).

### Declarations

Towards the bottom is the _declaration_ of the `hello()` function.
This is the same as in the _definition_ in `hello_world.c`, except that the declaration ends with a semicolon `;` instead of the function body.

This function takes no parameters (indicated by [`void`][void]).

Most functions have parameters, so these:

- _Must_ include the parameter type, and the compiler will enforce this.
- _Should_ also include the parameter name, as good style to make the header self-documenting.

For example:

```c
int remaining_minutes_in_oven(int actual_minutes_in_oven);
```

Many other things can be included in a header file, and you will see examples later in the syllabus.

### Guards

Lines beginning with `#` are preprocessor directives, to ensure that the compiler only includes the header file once.

- `HELLO_WORLD_H` is a constant, conventionally the file name converted to uppercase, with the dot replaced by underscore.
- `#ifndef` is an abbreviation of "if not defined": only continue if the `HELLO_WORLD_H` constant does not already exist.
- `#define` creates the constant.
- `#endif` closes the `#ifndef` block.

## Includes

The [`hello_world.c` file][hello-c] starts with an [`#include`][include] as the first line.

```c
#include "hello_world.h"
```

That tells the compiler's preprocessor to insert the contents of `hello_world.h` at the top of `hello_world.c`, as though it had been typed there.
The whole expanded file is then compiled.

There are two variants of `#include`:

- Those in double-quotes, as above, tell the compiler to search the project directory for the header file.
- Those in brackets, such as `#include <math.h>`, are for items in the standard library. The compiler will search for these in a central location, such as `\usr\include` (on Ubuntu systems).

Including system headers is very common in C code, even simple cases like an Exercism toy exercise.

Common examples include `stdio.h` (_for printing, etc_), `string.h`, `math.h`, `stdlib.h` (_for various C99 standard library functions_).

A typical *nix system probably has a few hundred system header files, available for you to use.

Future Concepts will note which imports are necessary to use the desired functions.

It may also be necessary to add a linker directive in the `makefile`, such as `LIBS = -lm` to use the math library, but that is a more advanced topic.

[hello-h]: https://github.com/exercism/c/blob/main/exercises/practice/hello-world/hello_world.h
[hello-c]: https://github.com/exercism/c/blob/main/exercises/practice/hello-world/hello_world.c
[void]: https://en.wikipedia.org/wiki/Void_type
[include]: https://en.wikipedia.org/wiki/Include_directive
