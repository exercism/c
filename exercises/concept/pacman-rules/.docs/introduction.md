# Introduction

A Boolean expression is a question asked of one or more values which can be answered with `true` or `false`.
A true expression returns `1`; a false expression returns `0`.
Also, numbers have true/false values. Zero is `false`; non-zero is `true`. 

Old C code will either use the `int` type directly for Boolean values, or the programmer may have defined constants such as `TRUE` and `FALSE` to map `1` and `0` to a Boolean representation.

With version C99 the `_Bool` type was added.
The `stdbool.h` header file defines three new Boolean symbols: `bool`; `true` and `false`.
`true` maps to `1`; `false` maps to `0`; and `bool` maps to `_Bool`.

So now, instead of directly using `int`s or rolling their own Boolean mappings, programmers can include `stdbool.h` and automatically get Boolean symbols in their code.

## Boolean Operators

C supports three boolean operators: `||` (Or), `&&` (And), and `!` (Not). 

`!` is used with one operand.
It reverses the Boolean value of the operand.
For instance, `0` is `false`, but `!0` is `true`.

`||` and `&&` are used with two operands.
The operand to the right is only evaluated when the operand to the left does not already determine the result of the expression.

That is, `||` only evaluates its operand to the right when its operand to the left evaluates to `false`.
`&&` only evaluates its operand to the right when its operand to the left evaluates to `true`.

## Precedence

The three boolean operators each have different _operator precedence_.
As a consequence, they are evaluated in this order: `!` first, `&&` second, and finally `||`.
If you want to force a different ordering, you can enclose a boolean expression in parentheses (ie. `()`), as the parentheses have even higher operator precedence.

```c
!true && false   // => false
!(true && false) // => true
```
