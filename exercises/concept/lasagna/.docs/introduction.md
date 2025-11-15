# Introduction

C is a statically typed language, which means that everything has a type at compile-time.
Choosing a name for a variable and setting its type is referred to as declaring a variable.

A variable is declared by explicitly specifying its type.
A variable name can start with either a letter or an underscore.

Some names cannot be used as they are reserved [for keywords][reserved-keywords] or [other identifiers][reserved-identifiers].

Setting or updating the variable is done by variable assignment.
Setting the value defines that variable.
Defining the variable is also known as initialization.

```c
int foo;      // Declare an integer named var
foo = 10;     // Define the variable

int bar = 15; // Both can also be done in a single statement
```

The value of a variable can be assigned and updated using the `=` simple assignment operator.
Once defined, a variable's type can never change.

```c
int foo = 10; // Assign initial value
foo = 25;     // Update to new value

foo = false;  // Compiler error when assigning value of a different type
```

If a value should not be changed after initialization, it can be declared as `const`. 
Attempted reassignment will then be flagged as an error.

```c
const int baz = 42;

// changes not allowed!
baz = 43
// => Error
```

C is an imperative procedural language.
All computation is carried out as part a series of statements that are part of a function or multiple functions.

Each function can have zero or more parameters.
When defining a function all parameters, and the return value must be explicitly typed.

Values are returned from functions using the `return` keyword.

Functions have `external storage class` by default, meaning that it exists for the lifetime of the program and can be visible externally to the file.

To prevent this, the `static` keyword can be added to specify visibility only within the current file.

```c
static int add(int x, int y) {
  return x + y;
}
```

In the above example, the variables `x` and `y` can only be used within the function that is, they have function scope.

Scope is the idea that the value associated with a name (of a program element) is only accessible within the code "area" where it is defined.

The principal code areas in C are:

- file
- function
- block (such as within loops and other constructs)

Functions are invoked by specifying the function name and passing arguments for each of the function parameters.

```c
int sum = add(1, 2);
```

C supports two types of comments.
Single line comments are preceded by `//` (since C99) and multi-line comments are inserted between `/*` and `*/`.

[reserved-keywords]: https://en.cppreference.com/w/c/keyword
[reserved-identifiers]: https://en.cppreference.com/w/c/language/identifier
