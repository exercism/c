# C Style Guide

This guide describes the style intended for use with the C track exercise example and test files.

The rules within this guide are in addition to, or to call out, those in the [Linux kernel coding style guide](https://www.kernel.org/doc/html/latest/process/coding-style.html).

## Names

In general, the names of types, variables, structures and files should use snake case with all letters in lower case and underscores `_` are used to separate name components.

```c
void some_foo_function(char * input_string, int input_string_length);
```

## Enums

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

## Macro names

Macros defining constants are named using snake case with all letters in upper case.

```c
#define CONSTANT 0x4000
```

Upper-case snake case for macro names is appreciated, but macros resembling functions may be named in lower-case snake case.

## Constant names

Names for variables defined as `const` (global or otherwise) should use snake case with all letters in upper case.

```c
const int LIMIT = 22;
```

## Type Names

Types defined by a program using `typedef` should be named with a `_t` suffix. 
While aware that POSIX reserves the `_t` suffix, the track does not currently utilise POSIX.

## Test file layout

Each exercise's test file follows a particular layout. 
The layout is intended to both help contibutors to identify parts of the file, and to help learners to understand how the tests work.

Like most C source files, a test file begins with includes. 

```c
#include "vendor/unity.h"
#include "../src/file_under_test.h"
// any other includes here
```

The includes are then followed by any helper functions that are used by the test functions.
The names of such helper functions should not use the `test_` prefix.

Next, there are the `setUp()` and `tearDown()` functions. 
So far, no exercise uses these (the function bodies are empty) yet they must remain in place to allow the test files to compile correctly across all platforms.

```c
void setUp(void)
{
}

void tearDown(void)
{
}
```

Next are the test functions themselves. 
The names of these functions use a `test_` prefix.

Last in the file is the `main()` function. 
The function body of main follows a particular layout itself. 
First a call to `UnityBegin()` followed by an empty line, then the tests. 
The last test is followed by another empty line and then a call to `UnityEnd()`, before returning.

```c
int main(void)
{
    UnityBegin("test/test_file_name.c");
    
    RUN_TEST(test_foo);
    RUN_TEST(test_bar);
    
    UnityEnd();
    return 0;
}
```
