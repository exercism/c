# About

## Conditional Statements

Conditional statements are decision-making statements that can either execute side-effects or control the flow of execution through a program.
Conditional statements include `if`, `if/else`, `switch`, and `ternary` statements.

Conditional statements are used to ask questions about a value or a relation of values.
The question evaluates to a Boolean answer, but the `if` statement itself can return any value or it can simply execute a side-effect.

## If Statements

The simplest `if` statement evaluates an expression and executes one line.
The expression being tested is always included in parentheses.

It can execute a side-effect

```c
if (count > 10)
    printf("count is greater than 10");
```

or it can change the flow of execution


```c
if (count > 10)
    return sum;
```

If an `if` statement executes more than one line it must place the lines within curly brackets

```c
if (count > 10) {
    printf("count is greater than 10");
    return sum;
}
```

Some coding teams may standardize that `if` statements should always use curly braces, even for one line.


## If Else

An `if` statement can be coupled with an `else`

```c
if (number % 2 == 0)
    return "even";
else
    return "odd";
```

## If Else If


`else` can be coupled with another `if` to create what's called an `if-else-if ladder`.

```c
if (number == 0)
    return "zero";
else if (number < 0)
    return "negative";
else if (number < 10)
    return "single digit";   
else if (number % 2 == 0)
    return "even";
else
    return "odd";
```

## Switch


Sometimes an `if-else-if ladder` can be better represented by a `switch`.
Like `if`, the expression being tested is always put in parentheses.

```c
switch (number) {
    case -1:
        return "negative one";
    case 0:
        return "zero";
    case 1:
        return "positive one";
    case 10:
        return "positive ten";
    case -10:
        return "negative ten";
    default:
        return "don't care";
}
```

The `default` case executes if the value being tested does not match any of the previous cases.

If a `switch` case is not returning then a `break` is usually inserted to end each case, otherwise the logic "falls through" to the next case.
Sometimes fallthrough is used intentionally

```c
switch (number) {
    case 0:
        msg = "zero"; break;
    case 1:
        msg = "one"; break;
    case 2: case 3: case 4:
        msg = "more than one and less than five"; break;
    default:
        msg = "don't care";
}
```

When fallthrough happens unintentionally it's a bug.

```c
switch (number) {
    case 0:
        msg = "zero"; // bug! fallthrough of 0 will set msg to "one"
    case 1:
        msg = "one"; break; 
    case 2: case 3: case 4:
        msg = "more than one and less than five"; break;
    default:
        msg = "don't care";
}
```

A switch can be beneficial when testing against specific values instead of a range of values.
It can be faster than an `if-else-if ladder` because the compiler may be able to optimize the `switch` statement in ways it can't do with a ladder.
A switch can sometimes look more readable than a ladder.

## Ternary (aka Conditional) Operator

The ternary operator is a three-part conditional statement that is often used for setting a value.
The expression to be tested is before the question mark and does not have to be in parentheses.
The value returned if true is before the colon, the value returned if false is after the colon.
Either a value literal or a variable can be returned.

```c
int i = j > 5 ? 5: j;
```

Ternary operators can be nested to reduce syntactic clutter.

```c
// the below could also be 
i = j > 5 ? j :k > 5 ? k: 10;
// but that may not be quite as readable

i = j > 5 ? j
    :k > 5 ? k
    :10;

// which is the same as
if (j > 5) i = j;
else if (k > 5) i = k;
else i = 10;
```

## Conditional Comparisions for Floating Point Values

Because of how floating point numbers are implemented, a simple math operation may result in a rounding error which can cause a test for equality to not return the expected result.

```c
    a = 1.345f;
    b = 1.123f;
    c = a + b;
    // c may equal something like 2.4679999352
    if (c == 2.468)
        return "I won the lottery!";
```

A tolerance value, referred to as `epsilon`, can be used to determine a range within which a value can fall to still be considered equal when compared with another value.
Be wary when comparing `float`s or `double`s for equality.
