# Introduction

A `bit` is the most granular value in computing.
The word `bit` stands for "binary digit".
It is a unit of data storage in the execution environment large enough to hold an object that may have one of two values.
As such, it has a binary value of either `1` or `0`.
All other data types consist of multiple `bits`.
For example, a `byte` commonly consists of eight `bits`.

## Bit Masks

A bit mask can be any value that is used for setting individual bits.
For instance, there are twenty-six letters in the English alphabet.
A value of at least twenty-six bits, such as an unsigned 32-bit integer, could be used as a bit mask to set a `true` or `false` condition for every English letter.
Any value with enough bits to handle a required set of `true` or `false` conditions can serve as a bit mask.
Setting and reading the individual bits is done through the use of bitwise operators.

## Bitwise Operators

Let's say we want to keep track of which letters occur in a `string`.
For our example, we will use only the twenty-six letters in the English alphabet.
Our bit mask will be an unsigned 32-bit integer.
A `0` will represent that the letter does not occur.
A `1` will represent that the letter occurs one or more times.
At the beginning, the bit representation of our bit mask will be 32 `0s` in a row: `00000000000000000000000000000000`.
The rightmost position will be for `A`.
Second from the left will be for `B`, and so on.
Say that we are processing all of the letters in the string in a loop, so we want one line of code that will work for setting any letter.

### Bitwise shift left operator: a way to position a bit

`<<` is the bitwise operator for shifting left.

If our letter is `A` we don't want to shift left, but if our letter is `B` we want to shift left one position, and if our letter is `C` we want to shift left two positions, and so on.
Although we can perceive `chars` as letters like `A` or `B`,  a `char` is implemented as an integer type in memory, so we can do simple math with a `char`.
Given a variable named `letter` which represents the `char` we are processing, we can shift left the required number of positions by shifting `1` to the left by the difference between `letter` and the `A` `char`, like so: `1 << letter - 'A'`.
`A` - `A` is `0`, so it would shift left `0` positions if `letter` is `A`.
`B` - `A` is `1`, so it would shift left `1` position if `letter` is `B`, and so on.

### Bitwise inclusive OR operator: a way to set a bit

Once we know _where_ we want to set a bit, we can actually set it by using the bitwise inclusive OR operator, which is `|`.
The result of the `|` operator will be `1` in each position where either the left or right operand has a bit set.
So, the result of `0010 | 0001` would be `0011`.
(It's important to remember that the value is `11` in binary, but is `3` in decimal.)
To assign the result to a value, the `|` operator can be combined with the assignment operator to set the bits like so: `|=`.
To keep it simple, the following example does not use a loop, but it demonstrates how we could process the letters `ABA` in a bit mask.

```c
#include <stdio.h>
#include <stdint.h>

int main() {
    // it's important to initialize the mask to 0 so we don't get garbage values
    uint32_t mask = 0;
    char letter_A = 'A';
    char letter_B = 'B';
    char letter_A_again = 'A';
    mask |= 1 << letter_A - 'A';
    mask |= 1 << letter_B - 'A';
    mask |= 1 << letter_A_again - 'A';
    // prints 3
    printf("%d", mask);
}
```

We set the rightmost part of our mask to `0001` for `A`, and then set the mask to `0011` for `B`.
Setting another `A` results in no change to the existing mask.
We could have avoided setting the bit again by looking to see if `A` had already been set.

### Bitwise AND operator: a way to read a bit

`&` is the bitwise AND operator.
The result of the `&` operator will be `1` in each position where both the left and right operand has a bit set.
So, the result of `0011 & 0001` would be `0001`.
We can see this in action in the following example.

```c
#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t mask = 0;
    char letter_A = 'A';
    char letter_B = 'B';
    char letter_A_again = 'A';
    mask |= 1 << letter_A - 'A';
    mask |= 1 << letter_B - 'A';
    // prints A already set
    if (mask & 1 << letter_A_again - 'A')
        printf("A already set\n");
    else
        mask |= 1 << letter_A_again - 'A';
    printf("%d", mask);
}
```

### Bitwise exclusive OR operator: a way to flip a bit

`^` is the bitwise exclusive OR operator.
An _inclusive_ OR operator implies that there is an _exclusive_ OR operator with different behavior.
The result of the `^` operator will be `1` in each position where _only one_ of the left or right operands has a bit set.
So, the result of `0001 ^ 0011` would be `0010`.
The rightmost bit will not be set because _both_ operands have `1` in the rightmost position.
The exclusive OR operation is sometimes notated as XOR.
If the result of a value that is XOR'd is itself XOR'd it will return the original value.
This can be used for a very simple encryption where the same key is used to both encrypt and decrypt the data.
For example

```c
#include <stdio.h>

int main() {
    char a = 'a';
    char b = 'b';
    char c = 'c';
    // we will use "a" for the "key"
    char first = a ^ 'a';
    char second = b ^ 'a';
    char third = c ^ 'a';
    // prints three "dots" for unprintable characters
    printf("%c %c %c\n", first, second, third);
    // prints the ascii values 0 3 2
    printf("%d %d %d\n", first, second, third);
    first = first ^ 'a';
    second = second ^ 'a';
    third = third ^ 'a';
    // prints a b c
    printf("%c %c %c\n", first, second, third);
    // prints the ascii values 97 98 99
    printf("%d %d %d\n", first, second, third);
}
```

## Bit Fields

We've seen how bits packed into a simple data type can be addressed by their position.
Bits packed into a `struct` can be addressed by name.
Such a data type is called a `bit field`.
A use case for `bit fields` can be when a collection of ON/OFF flags is needed and the minimizing of memory use is desired.

```c
#include <stdio.h>

int main() {

    struct lights {
        unsigned int number_of_lights;
        unsigned int red   : 1;
        unsigned int green : 1;
        unsigned int blue  : 1;
    };
    struct lights lightboard = {3, 0, 0, 0};
     
    //  prints 000
    printf("%d", lightboard.red);
    printf("%d", lightboard.green);
    printf("%d\n", lightboard.blue);
    
    lightboard.green = 1;

    //  prints 010
    printf("%d", lightboard.red);
    printf("%d", lightboard.green);
    printf("%d\n", lightboard.blue);
    
    // prints 3
    printf("%d\n", lightboard.number_of_lights);
}
```

The syntax of `unsigned int variable_name : 1;` creates a field of `1` bit within an `unsigned int` placed within the struct.
Instead of an `unsigned int`, a `signed int` could be used, or, as of C99 or later, a `bool` type could be used.
A struct containing bit fields can also contain fields of other data types, such as `number_of_lights` in the above example.
