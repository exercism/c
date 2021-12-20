# About

A Boolean expression is a question asked of one or more values which can be
answered with `true` or `false`. A true expression returns `1`; a false
expression returns `0`. Also, numbers have true/false values. Zero is false`;
non-zero is `true`. 

Old C code will either use the `int` type directly for Boolean values, or the
programmer may have defined constants such as `TRUE` and `FALSE` to map `1` and
`0` to a Boolean representation.

With version C99 the `_Bool` type was added. The `stdbool.h` header file defines
three new Boolean symbols: `bool`; `true` and `false`. `true` maps to `1`;
`false` maps to `0`; and `bool` maps to `_Bool`. So now, instead of directly using 
`int`s or rolling their own Boolean mappings, programmers can include `stdbool.h`
and automatically get Boolean symbols in their code.

## Comparison Operators

C supports six comparison operators: `==` (Equal), `!=` (Not equal), `>` (Greater
than), `<` (Less than), `>=`(Greater than or equal to), `<=` (Less than or equal
to). These operators can compare values to evaluate the relationship of values
into a boolean value.

```c
0 == 0 // true. Although 0 is false, 0 equals 0 is true.
0 != 0 // false
1 > 0 // true
1 < 0 // false
1 >= 0 // true
1 <= 0 // false
```

## Boolean Operators

C supports three boolean operators: `||` (Or), `&&` (And), and `!` (Not). 

`!` is used with one operand. It reverses the Boolean value of the operand. For
instance, `0` is `false`, but `!0` is `true`.

`||` and `&&` are used with two operands. The operand to the right is only
evaluated when the operand to the left does not already determine the result of
the expression. That is, `||` only evaluates its operand to the right when its
operand to the left evaluates to `false`. `&&` only evaluates its operand to the
right when its operand to the left evaluates to `true`.


## Short-circuiting

To not evaluate all operands is known as "short-circuiting". Short-circuiting is a
succinct and powerful way to handle certain situations. For example, a common
idiom is to check if a pointer is not `NULL` and (&&), if it is not `NULL`, to
then dereference it, thus avoiding dereferencing a `NULL` pointer. But short-
circuiting can also lead to bugs. Sometimes a programmer forgets that the right-
hand operand of `||` or `&&` may not always be evaluated. If the right-hand
operand is an expression with a side effect that is expected to always happen,
then it will be a bug depending on the Boolean value of the left-hand operand.


##Returning a Boolean Expression

The result of a Boolean expression can be directly returned. For example, this
`if` statement

```c
if (count > 0)
    return true;
else
    return false;
end
```

could be replaced by

```c
return count > 0;
```
