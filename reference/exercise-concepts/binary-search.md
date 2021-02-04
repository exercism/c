# Concepts of binary-search

[Example Implementation](https://github.com/exercism/c/blob/master/exercises/binary-search/src/example.c)

- [Arithmetic](https://github.com/exercism/v3/blob/master/reference/concepts/arithmetic.md): Used to calculate the limits between which to search the value
- [Comparisons](https://github.com/exercism/v3/blob/master/reference/concepts/comparisons.md): Comparisons are used in if and while loop conditions
- [Function definitions](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Definitions): Used as the main entry point for the exercise
- [Function parameters](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Parameters): The definition of the function under test uses the parameters `value`, `arr` and `length`
- [Header files](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Header-Files): Used to access the standard library for `size_t`, an unsigned integral type
- [Integer](https://github.com/exercism/v3/blob/master/reference/types/integer.md): Integers are used throughout
- [Operators](https://github.com/exercism/v3/blob/master/reference/concepts/operators.md): Operators are used throughout for the arithmetic
- [The if statement](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-if-Statement): If statements are used to decide in which part of the array to search for the index to return
- [The return statement](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-return-Statement): The index of the searched value is returned if the value is found, `NULL` otherwise
- [The while statement](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-while-Statement): Loop to find the searched value
- [Variables](https://github.com/exercism/v3/blob/master/reference/concepts/variables.md): Used to create the limits of the search interval
- [Pointers](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Pointers): The parameter `arr` to the function under test is an int passed by pointer
- [Nullability](https://github.com/exercism/v3/blob/265953042ed67f5404f498656c2c23bdce708af5/reference/types/null.md): `NULL` is returned if the searched value was not found
