# About

A block is a set of statements and declarations grouped into one syntactic unit.
Blocks are often, but not always, defined within curly braces.

In the following example, `number` is defined within the `main` function.
`flag` is defined within the `if` block.
Variables defined within a block are only valid within the block.
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
However, `flag` is defined within a block in the function.
The block can "see" the variable `number` in the function, but the function can't "see" the `flag` variable defined within the block.
Once execution leaves the block, the `flag` variable is automatically destroyed and is no longer available to the program.
The function itself sees `flag` identifier for the first time in the last `printf` statement.
If the last `printf` statement is removed, the program will print `1`.
That is because the `flag` variable is valid in the block containing the first `printf` statement.

