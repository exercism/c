# About

A block is a set of statements and declarations grouped into one syntactic unit.
Blocks are often, but not always, defined within curly braces.
Blocks can be nested within functions and within other blocks.

In the following example, `number` is defined within the `main` function.
`flag` is defined within the `if` block which is nested within the `main` function.
Variables defined within a block are only valid within that block.
Thus, attempting to compile the code results in a compilation error.

```c
#include <stdio.h>

int main() {

  int number = 1;

  if (number == 1) {
      int flag = 1;
      printf("%d", flag);
  }

  // this line generates a compilation error
  // error: 'flag' undeclared (first use in this function)
  printf("%d", flag);
    
}
```

The error message may be confusing, as `flag` _is_ used earlier in the function.
However, `flag` is defined within a block inside the function.
The inner block can "see" the variable `number` in its outer function, but the outer function can't "see" the `flag` variable defined within its inner block.
Once execution leaves the block, the `flag` variable is automatically destroyed and is no longer available to the program.
The `main` function itself sees the `flag` identifier for the first time in the last `printf` statement.
If the last `printf` statement is removed, the program will compile and print `1` when run.
That is because the `flag` variable is valid in the block containing the first `printf` statement.

As of `C99`, single-line `if`, `for`, `while` and `do` statements are also considered blocks.
In the following example, although `i` is not defined within curly braces, it exists only in the block defined by the `for` statement, and is not visible to the outer `main` function.

```c
#include <stdio.h>

int main() {

    for (int i = 0, j = 11; i < j; i+=2)
        printf("%d", i);

    // this line generates a compilation error
    // error: 'i' undeclared (first use in this function)
    printf("%d", i);
    
}
```

If the last `printf` statement is removed, the program will compile and print `0 2 4 6 8 10 ` when run.
Some languages, such as Go and Rust, are explicit that single-line conditional and loop statements constitute a block.
They require that such single-line statements still be enclosed in curly braces.
