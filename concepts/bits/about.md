# About

A `bit` is the most granular value in computing.
The word `bit` stands for "binary digit".
It is a unit of data storage in the execution environment large enough to hold an object that may have one of two values.
As such, it has a binary value of either `1` or `0`.
All other data types consist of multiple `bits`.
For example, a `byte` commonly consists of eight `bits`.

## How to write bit values

`Bits` make up a base 2 number system.
Every multiple of `2` is put into what we think of as the tens/hundreds/thousands/etc. place, except that "tens" would be "two", "hundreds" would be "four", "thousands" would be "eight", and so on.
So, the decimal value `2` would be `10`, `4` would be `100`, and `8` would be `1000`.
Like decimal numbers, the values become higher as they go from right to left.
We can think of the decimal value `5` being represented by `101` in binary, with a `1` in the "ones" place and a `1` in the "four" place.
However, binary literals are not part of the `C` language standard.
The only binary values supported by the `C` language standard are a single `1` or `0`.
Binary literals _are_ supported by some non-standard compiler extensions, such as the gnu compiler, by prefacing the literal with `0b`.

```c
#include <stdio.h>

int main() {
    int binary_five = 0b101;
    printf("%d", binary_five);
    return 0;
}
```

It is important to remember that such a notation is not supported by all compilers and could be a barrier to code portability between different compilers.

A common way to code binary values is to use hexadecimal notation, which is a base 16 number system.
`C` language hexadecimal notation prefaces the literal with `0x` or `0X`.
Since the decimal value `16` is represented as `1` in the tens place, the decimal value `10` is represented as `0xA` in hexadecimal, `11` as `0xB`, `12` as `0xC`, `13` as `0xD`, `14` as `0xE` and `15` as `0xF`.
So, for example, the decimal value `42` would be written as `0x2A`: `2` times `16` (= `32`) plus `10` (= `42`).

In binary, we can think of `42` as `00101010`: `32` plus `8` plus `2`.
We would say that the second, fourth, and sixth bits are "set", meaning that they are `1` instead of `0`.
The second bit is `2`, the fourth bit is `8`, and the sixth bit is `32`.
Setting those three bits defines a value of `42`.

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
Given a variable named `letter` which is the `char` we are processing, we can shift left the required number of positions by shifting `1` to the left by the difference between `letter` and the `A` `char`, like so: `1 << letter - 'A'`.
`A` - `A` is `0`, so it would shift left `0` positions.
`B` - `A` is `1`, so it would shift left `1` position, and so on.

### Bitwise inclusive OR operator: a way to set a bit

Once we know _where_ we want to set a bit, we can actually set it by using the bitwise inclusive OR operator, which is `|`.
The result of the `|` operator will be `1` in each position where either the left or right operand has a bit set.
So, the result of `0010 | 0001` would be `0011`.
(It's important to remember that the value is `11` in binary, but is `3` in decimal.)
To assign the result to a value, the `|` operator can be combined with the assignment operator to set the bits like so: `|=`.
To keep it simple, the following example does not use a loop, but it demonstrates how we could process the letters 'ABA` in a bit mask.

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



## Bit Fields
