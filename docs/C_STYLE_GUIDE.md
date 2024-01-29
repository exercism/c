# C Style Guide

This guide describes the style intended for use with the C track exercise example and test files.

The rules within this guide are in addition to, or to call out, those set by the [.clang-format][]file.

## C Standard

Code should conform to the C99 standard, more formally known as ISO/IEC 9899:1999.
POSIX, or otherwise non-standard library functions, types or other references that are external to the implementation should not be used.

## Names

In general, the names of types, variables, structures and files should use snake case with all letters in lower case and underscores `_` are used to separate name components.

```c
void some_foo_function(char * input_string, int input_string_length);
```

### Enums

Enum names should usually be singular rather than plural.

Enum labels should use snake case with all letters in upper case.

```c
enum heading {
    HEADING_NORTH,
    HEADING_EAST,
    HEADING_SOUTH,
    HEADING_WEST
}
```

### Macros

Macros defining constants are named using snake case with all letters in upper case.

```c
#define CONSTANT 0x4000
```

Upper-case snake case for macro names is appreciated, but macros resembling functions may be named in lower-case snake case.

### Types

The standard fixed-width types (in `stdint.h`) are preferred over basic integer types.

The type `bool` (from `stdbool.h`) is preferred over `_Bool`.

Likewise, `size_t` and `ptrdiff_t` (of `stddef.h`) are preferred for representing memory-related quantities.

Types defined by a program using `typedef` should be named with a `_t` suffix.
While aware that POSIX reserves the `_t` suffix, the track does not currently utilise POSIX.

## Include Guards

Include guards should be used in all header files.

Generally, one set of include guards should wrap the full contents of the header.

Guards in the example implementation (`.meta/example.h`) and the exercise stub (`exercise_name.h`) should use macro names that follow the exercise name.
Guard macro names should follow the above rule for macros regarding casing.

For example, for the exercise `hello-world`, use:

```c
#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

//...

#endif
```

## Parameters

Function parameters should be named in both the declaration and definition of all functions.
This applies to both `.c` and `.h` files.
The names used should match in all instances.
That is to say that while the following function prototype is valid C, the style is incorrect because the parameter is unnamed: `void foo(int);`.
The correct prototype, providing that all other declarations and the definition also use the parameter name `bar`, would be `void foo(int bar);`.

Where it is simpler or more appropriate to do so, parameters that require passing arguments by value rather than by pointer are preferred.
Note especially that this includes `struct` type parameters.

In the case that a student is not expected to change the values of a pointer-type parameter within their implementation, that parameter should be `const` qualified.

## Format

The repository uses the `clang-format` tool, as outlined in the [contributing guide][].

## Test file layout

the test file of each exercise follows a particular layout.
The layout is intended to both help contributors to identify parts of the file, and to help learners to understand how the tests work.

Like most C source files, a test file begins with includes.

```c
#include "vendor/unity.h"
#include "../src/file_under_test.h"
// any other includes here
```

The includes are then followed by the `setUp()` and `tearDown()` functions.
So far, no exercise uses these (the function bodies are empty) yet they must remain in place to allow the test files to compile correctly across all platforms.

```c
void setUp(void)
{
}

void tearDown(void)
{
}
```

Next are any helper functions that are used by the test functions.
The names of such helper functions should not use the `test_` prefix.

Next are the test functions themselves.
The names of these functions use a `test_` prefix.
Excepting the first, each test function should have `TEST_IGNORE();` as its first statement.
The first occurrence of this should be followed by the line comment `// delete this line to run test`.

For example:

```c
static void test_the_first(void)
{
   test_first_foo();
}

static void test_the_second(void)
{
   TEST_IGNORE();               // delete this line to run test
   test_second_foo();
}

static void test_the_third(void)
{
   TEST_IGNORE();
   char grade = 'A';
   test_third_foo(grade);
}
```

Last in the file is the `main()` function.
The function body of main follows a particular layout itself.
First a call to `UNITY_BEGIN()` followed by an empty line, then the tests.
The last test is followed by another empty line before returning the result of `UNITY_END()`.

```c
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_foo);
    RUN_TEST(test_bar);

    return UNITY_END();
}
```

[.clang-format]: ./../.clang-format
[contributing guide]: ./CONTRIBUTING.md
