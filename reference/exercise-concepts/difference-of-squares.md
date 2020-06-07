# Concepts of difference-of-squares

[Example Implementation](https://github.com/exercism/c/blob/master/exercises/difference-of-squares/src/example.c)

- [Arithmetic](https://github.com/exercism/v3/blob/master/reference/concepts/arithmetic.md): Several simple calculations are used
- [Calling functions](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Calling-Functions): The `difference_of_squares()` function can call other required functions to prevent code duplication
- [Comparisons](https://github.com/exercism/v3/blob/master/reference/concepts/comparisons.md): Used to decide on the calculations required
- [Function definitions](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Definitions): Used as the main entry point for the exercise
- [Function parameters](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Function-Parameters): The definition of the functions under test uses parameters
- [Header files](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Header-Files): Header files are included
- [Integer types](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Integer-Types): Integers are used throughout
- [Operators](https://github.com/exercism/v3/blob/master/reference/concepts/operators.md): Used to calculate the sums, squares and difference
- [Scope](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Scope): Summing variables are used outside of loop scopes to allow further use of the value
- [Signedness](https://github.com/exercism/v3/blob/master/reference/concepts/signedness.md): Parameters and return values of the functions under test are unsigned
- [The for statement](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-for-Statement): A for loop is used to calculate the square of a sum
- Underflow: Some implementations could result in underflow
  - [Arithmetic underflow](https://en.wikipedia.org/wiki/Arithmetic_underflow)
  - [Impacts of underflow](https://www.gnu.org/software/libc/manual/html_node/Math-Error-Reporting.html)
- Overflow: Some implementations could result in overflow
  - [Integer underflow](https://en.wikipedia.org/wiki/Integer_overflow)
  - [Impacts of underflow](https://www.gnu.org/software/libc/manual/html_node/Math-Error-Reporting.html)
- [Variables](https://github.com/exercism/v3/blob/master/reference/concepts/variables.md): variables are used for summing values
