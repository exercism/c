# Introduction

Recursion is a way to repeat code in a function by the function calling itself.
It is another way to loop/iterate. Like looping, the function should test a Boolean expression to know when to end.
Unlike looping, recursion that never ends will not run infinitely.
The values used in each function call may be placed in their own frame on the stack.
If the amount of function calls takes up more space than the stack has, it will result in a stack overflow error.

```c
int printIncrement (int i, int maxValue){
    if (i > maxValue) return i;
    printf("The number is %i\n", i++);
    printIncrement(i, maxValue);
}

int main() {
    printIncrement(1, 2);
    printf("After recursion");
    return 0;
}
```

This will print

```
The number is 1
The number is 2
After recursion
```

There may be some situations that are more readable and/or easier to reason through when expressed through recursion than when expressed through looping.
