# C Style Guide

This guide describes the style intended for use with the C track exercise example and test files.

The rules within this guide are in addition to, or to call out, those in the [Linux kernel coding style guide](https://www.kernel.org/doc/html/latest/process/coding-style.html).

## C Standard

Code should conform to the C99 standard, more formally known as ISO/IEC 9899:1999. POSIX, or otherwise non-standard library functions, types or other references that are external to the implementation should not be used.

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

## Parameters

Function parameters should be named in both the declaration and definition of all functions. This applies to both `.c` and `.h` files. 
The names used should match in all instances.
That is to say that while the following function prototype is valid C, the style is incorrect because the parameter is unnamed: `void foo(int);`.
The correct prototype, providing that all other declarations and the definition also use the parameter name `bar`, would be `void foo(int bar);`.

Where it is simpler or more appropriate to do so, parameters that require passing arguments by value rather than by pointer are preferred. Note especially that this includes `struct` type parameters.

In the case that a student is not expected to change the values of a pointer-type parameter within their implementation, that parameter should be `const` qualified.

## Indentation and Format

The repository uses the `indent` tool, as outlined in the [contributing guide](https://github.com/exercism/c/blob/master/docs/CONTRIBUTING.md).

The options described for use with indent there are `-linux -i3 -nut`. The `-linux` option is a shortcut that is equivelent to a secific fixed group of options. The combined equivalent options are `-nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1`.

What these options do is indicated by the [GNU `indent` manual](https://www.gnu.org/software/indent/manual/indent.html#SEC4), but is also described here for easy reference if editing files manually.

- `nbad` - Do _not_ force blank lines after every block of declarations
- `bap` - Force a black line after every function body
- `nbc` - Do _not_ force a newline after each comma in a declaration
- `bbo` - Prefer to break long lines before the boolean operators `&&` and `||`
- `hnl` - Honour newlines in the file by giving them the highest possible priority to break lines at
- `br` - Place an opening brace on the same line as the `if (condition)`
- `brs` - Place an opening brace on same line as `struct struct_name`
- `c33` - Put comments to the right of code in column 33
- `cd33` - Put comments to the right of the declarations in column 33
- `ncdb` - Do _not_ put comment delimiters on blank lines
- `ce` - Place the `else` on the same line as the preceding closing brace, so the it is 'cuddled' like so `} else {`
- `ci4` - Indent by 4 spaces for hard line-breaks within statements (continuation indentation)
- `cli0` - Indent case labels by 0 spaces to the right of the containing switch statement
- `d0` - Set indentation of comments, that are _not_ to the right of code, to 0 spaces.
- `di1` - Line up identifiers in the first column
- `nfc1` - Do _not_ format comments that are in the first column
- `i3` - Set the indentation level to 3 spaces
- `nut` - Use spaces instead of tabs
- `ip0` - Use 0 extra offset indentation for breaks between two or more parenthesis pairs `(...)`
- `l80` - The maximum length of a line of C code is 80, not including possible comments that follow it
- `lp` - Line up continued lines at parentheses
- `npcs` - Do _not_ put space between the name of the function being called and the ‘(’, eg `puts("Hi");` not `puts ("Hi");`)
- `nprs` - Do _not_ put a space after every '(' and before every ')'
- `npsl` - Put the type of a function on the same line as its name
- `sai` - Force a space between an `if` and the following parenthesis
- `saf` - Force a space between a `for` and the following parenthesis
- `saw` - Force a space between a `while` and the following parenthesis
- `ncs` - Do _not_ put a space after cast operators
- `sob` - Swallow (remove) any optional blank lines
- `nfca` - Do _not_ format any comments
- `cp33` - Put comments to the right of `#else` and `#endif` statements in column 33
- `ss` - On one-line `for` and `while` statements, force a blank before the semicolon, like so `while (condition) ;`
- `il1` - Set the offset for labels to column 1

## Test file layout

Each exercise's test file follows a particular layout. 
The layout is intended to both help contibutors to identify parts of the file, and to help learners to understand how the tests work.

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
void test_the_first(void)
{
   test_first_foo();
}

void test_the_second(void)
{
   TEST_IGNORE();               // delete this line to run test
   test_second_foo();
}

void test_the_third(void)
{
   TEST_IGNORE();
   char grade = 'A';
   test_third_foo(grade);
}
```

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
