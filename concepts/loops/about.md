# About
A loop is a way of repeatedly calling one or more statements in a batch.
Each run of a batch of statements is called an iteration.

## While loop

A `while` loop executes a batch of statements while a Boolean expression at the top of the loop is true.
When the Boolean expression is false the loop stops running and execution proceeds to the next line of code after the loop.

If the Boolean expression evaluates to false from the beginning the `while` loop will not run at all and execution will proceed to the next line of code after the loop.

```c
int main() {
    int i = 0;
    while (i < 5) {
        printf("Number is %i\n", i++);
    }    
    return 0;
}
```

It is important for there to be a condition to end the loop; otherwise it is an infinite loop which will block all progress of the code.
If the above code had the `++` removed from `i` it would be an infinite loop.

## Do loop

A `do` loop has its Boolean expression tested at the bottom of the loop.
A `do` loop will always run at least once, as in the following example

```c
do {
    printf("Enter the Answer to the Ultimate Question of Life: ");
    scanf("%d", &answer);
} while (answer != 42); 
// Note that a semicolon is needed after the Boolean expression.
```

With a `while` loop this would be more verbose

```c
printf(""Enter the Answer to the Ultimate Question of Life: ");
scanf("%d", &answer);
while (answer != 42) {
    printf(""Enter the Answer to the Ultimate Question of Life: ");
    scanf("%d", &answer);
}
```

## For loop

Often a loop will update a variable and end when the variable reaches a certain value.
A `for` loop is a way of initializing, updating and testing one or more variables in one line within parentheses.
The first section is for initializing the variable, the second section for testing the variable, and the third section is for updating the value of the variable.

```c
for (int i = 0; i < 5; i++) {
    printf("Number is %i\n", i);
}
```

This is less verbose than the `while` loop equivalent, and yet it is still readable.

The initializing and updating sections of the `for` loop may handle more than one variable by using the comma operator to separate expressions within the conditions.

```c
    int i, j;
    for (i = 0, j = 5; i < 5 && j > 2; i++, j--) {
        printf("i is %i\n", i);
        printf("j is %i\n", j);
    }
    printf("After the loop");
```

This will print

```
i is 0
j is 5
i is 1
j is 4
i is 2
j is 3
After the loop
```

None of the sections of the `for` need to be defined.
An empty testing expression evaluates to true, so a `for` loop could be used to define an infinite loop like so

```c
int i = 0;
for (;;) {
    printf("Number is %i\n", i++);
    if (i == 5) break;
}
```

This is similar to the `while` loop in that `i` is initialized before the loop and is incremented inside the loop.
Also, `i` is tested inside the loop and the loop ends with the `break` statement.

## Break statement

Sometimes a loop may need to end on a special condition not tested in its Boolean expression.
The `break` statement will end the loop and execution will proceed to the next line of code after the loop.

```c
int i, j, k;
for (int i = 0, j = 5, k = 3; i < 5 && j > 2; i++, j--) {
    printf("i is %i\n", i);
    printf("j is %i\n", j);
    if (k == 3) break;
}
printf("After the loop");
```

This will print

```
i is 0
j is 5
After the loop
```

## Continue statement

Sometimes a loop may need to start its next iteration without completing its current iteration.
The `continue` statement stops execution of the current iteration and continues execution at the start of the next iteration.

```c
int i, j;
for (int i = 0, j = 4; i < 4 && j > 0; i++, j--) {
    if (i == j) continue;
    printf("i is %i\n", i);
    printf("j is %i\n", j);
}
printf("After the loop");
```

This will print

```
i is 0
j is 4
i is 1
j is 3
i is 3
j is 1
After the loop
```

It does not print the values for `i` and `j` when they are both `2`.
