# Introduction

A loop is a way of repeatedly calling one or more statements in a batch. Each 
run of a batch of statements is called an iteration.

## While loop

A `while` loop executes a batch of statements while a Boolean expression at the 
top of the loop is true. When the Boolean expression is false the loop stops 
running and execution proceeds to the next line of code after the loop.

If the Boolean expression evaluates to false from the beginning the `while` loop
will not run at all and execution will proceed to the next line of code after
the loop.

```c
int main() {
    int i = 0;
    while (i < 5) {
        printf("Number is %i\n", i++);
    }    
    return 0;
}
```

It is important for there to be a condition to end the loop; otherwise it is an
infinite loop which will block all progress of the code. If the above code had
the `++` removed from `i` it would be an infinite loop.

## Do loop

A `do` loop has its Boolean expression tested at the bottom of the loop. A `do`
loop will always run at least once, as in the following example

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

Often a loop will update a variable and end when the variable reaches a
certain value. A `for` loop is a way of initializing, updating and testing
one or more variables in one line within parentheses. The first section is for
initializing the variable, the second section for testing the variable, and
the third section is for updating the value of the variable.

```c
for (int i = 0; i < 5; i++) {
    printf("Number is %i\n", i);
}
```

This is less verbose than the `while` loop equivalent, and yet it is still
readable.
