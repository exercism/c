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

## Bitwise Operators

## Bit Masks

## Bit Fields
