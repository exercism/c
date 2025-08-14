# About

C is a statically typed language, which means that everything has a type at compile-time.
Choosing a name for a [variable][variable] and setting its type is referred to as declaring a variable.

A variable is declared by explicitly specifying its type.
A variable name [must follow some rules][name-rules] like starting with either a letter or an underscore.
Some names cannot be used as they are reserved [for keywords][reserved-keywords] or [other identifiers][reserved-identifiers].

Setting or updating the variable is done by variable assignment.
Setting the value defines that variable.
Defining the variable is also known as initialization.

```c
int foo;      // Declare an integer named var
foo = 10;     // Define the variable

int bar = 15; // Both can also be done in a single statement
```

The value of a variable can be assigned and updated using the [`=` simple assignment operator][assignment-operator].
Once defined, a variable's type can never change.

```c
int foo = 10; // Assign initial value
foo = 25;     // Update to new value

foo = false;  // Compiler error when assigning value of a different type
```

C is an [imperative][imperative] [procedural][procedural] language.
All computation is carried out as part a series of [statements][statements] that are part of a [function][function] or multiple functions.

Each function can have zero or more [parameters][parameters].
When defining a function all parameters, and the return value must be explicitly typed.
Values are returned from functions using the [`return` keyword][return-keyword].
Functions have external [storage class][storage_class] by default, meaning that it exists for the lifetime of the program and can be visible externally to the file.
To prevent this the `static` keyword can be added to specify internal visibility.

```c
static int add(int x, int y) {
  return x + y;
}
```

In the above example, the variables `x` and `y` can only be used within the function that is, they have function scope.
[Scope][scope] is the idea that the value associated with a name (of a program element) is only accessible within the code "area" where it is defined.
The principal code areas in C are:

- file
- function
- block (such as within loops and other constructs)

Functions are invoked by specifying the function name and passing arguments for each of the function parameters.

```c
int sum = add(1, 2);
```

C supports two types of [comments][comments].
Single line comments are preceded by `//` (since C99) and multi-line comments are inserted between `/*` and `*/`.

[variable]: https://www.w3schools.in/c-tutorial/variables/
[name-rules]: https://www.tutorialspoint.com/what-is-an-identifier-and-its-rules-in-c-language
[reserved-keywords]: https://en.cppreference.com/w/c/keyword
[reserved-identifiers]: https://en.cppreference.com/w/c/language/identifier
[assignment-operator]: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Assignment-Operators
[imperative]: https://en.wikipedia.org/wiki/Imperative_programming
[procedural]: https://en.wikipedia.org/wiki/Procedural_programming
[statements]: https://docs.microsoft.com/en-us/cpp/c-language/overview-of-c-statements
[parameters]: https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_056.HTM
[return-keyword]: https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-return-Statement
[storage class]: https://www.programiz.com/c-programming/c-storage-class
[scope]: https://www.geeksforgeeks.org/scope-rules-in-c/
[comments]: https://en.wikipedia.org/wiki/Comment_(computer_programming)
[function]: https://en.wikipedia.org/wiki/Function_(computer_programming)
