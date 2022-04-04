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

A function acts somewhat like a block.
An identifier for a variable defined in a function cannot be seen outside the function, just as an indentifier for a variable defined in a block cannot be seen outside the block.
Two variables in two functions can have the same name, since the two functions don't see into each other, just as two variables in two blocks can have the same name, since the two blocks don't see into each other.
But functions and blocks are not identical.
A function cannot be defined inside another function, but a block can be nested inside another block.
And some identifiers in a block can be seen outside the block.
In the following example, the code will not compile

```c
#include <stdio.h>

int main() {

  {
      int i = 0;
      begin:
      printf("i == %d\n", i);
      if (i == 0) {
          i = 1;
          goto begin;
      }
  }

  {
      int i = 1;
      begin:
      printf("i == %d\n", i);
      if (i == 1) {
          i = 0;
          goto begin;
      }
  }

}
```

The code above fails to compile with the following error

```
/tmp/gH2TVYnTSJ.c: In function 'main':
/tmp/gH2TVYnTSJ.c:17:5: error: duplicate label 'begin'
   17 |     begin:
      |     ^~~~~
/tmp/gH2TVYnTSJ.c:7:5: note: previous definition of 'begin' was here
    7 |     begin:
      |     ^~~~~
```

Although `i` can be defined in each block, `label` names must be unique in a function.
That is because `labels` have function scope, meaning each label is seen by the function no matter where in the function it is defined.
So, unlike variables, no matter where a `label` is defined in a function it must have a unique name within that same function.
To make the code work requires changing the name of one of the `labels` so they are both unique, as in the following example

```c
#include <stdio.h>

int main() {

    {
        int i = 0;
        begin:
        // prints
        // i == 0
        // i == 1
        printf("i == %d\n", i);
        if (i == 0) {
            i = 1;
            goto begin;
        }
    }

    {
        int i = 1;
        start:
        // prints
        // i == 1
        // i == 0    
        printf("i == %d\n", i);
        if (i == 1) {
            i = 0;
            goto start;
        }
    }

}
```

Single-line statements can be "stacked" and still be within one block without the use of curly braces.
In the example below, the `for` statement contains an `if` statement which in turn contains a `printf` statement.
Although there are two total statements in the `for` block, it "sees" only its single-line `if` statement.
The `if` statement in turn "sees" its single-line `printf` statement.
Note that the comment does not require curly braces for enclosing it and the `printf` statement within the `if` block, since the comment is not a statement.
The indentation makes it clear what's happening, but a development team may have have its own coding guidelines about placing curly braces in such situations to remove any kind of ambiguity.

```c
#include <stdio.h>

int main() {

    for (int i = 0, j = 11; i < j; i++)
        if (i & 1 == 1)
            // prints 1 3 5 7 9 
            printf("%d ", i);
}
```

We've seen that values defined within a block cannot be accessed from outside of the block.
And we've seen that values defined outside of a block can usually be accessed from within the block.
It is possible for a variable outside of a block to be hidden inside a block if the identifier for that variable is used in defining a block variable.
In the following example, the `number` identifier is used for both a function-level variable and a block-level variable.
We say that the block-level variable hides or _shadows_ the function-level variable.

```c
#include <stdio.h>

int main() {
    int number = 1;
    // prints number in function is 1
    printf("number in function is %d\n", number);
    
    if (number == 1) {
        // the definition of a block-level variable using the same name
        // shadows the function-level variable
        int number = 2;
        // prints number in function is 2
        printf("number in if block is %d\n", number);
    }
    // prints number in function is 1
    printf("number in function is %d\n", number);
}
```

Compilers may generate an error if a function parameter is attempted to be shadowed.
The following example

```c
#include <stdio.h>

void print_number(int number) {
    // will fail to compile
    int number = 2;
    printf("number in function is %d\n", number);
}

int main() {
    int number = 1;
    printf("number in main is %d\n", number);
    print_number(number);
    printf("number in main is %d\n", number);
}
```

results in the following errors on two platforms

```
/tmp/jIvhD5UOop.c: In function 'print_number':
/tmp/jIvhD5UOop.c:5:9: error: 'number' redeclared as different kind of symbol
    5 |     int number = 2;
      |         ^~~~~~
/tmp/jIvhD5UOop.c:3:23: note: previous definition of 'number' was here
    3 | void print_number(int number) {
      |                   ~~~~^~~~~~
```

and

```
redefinition of formal parameter 'number'
```
