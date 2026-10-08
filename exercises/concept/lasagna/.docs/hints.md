# Hints

To repeat: please do not alter the `lasagna.h` file or the `#include` line.

These are designed to make this introductory exercise simpler for students.

## 1. Define the expected oven time in minutes

- This is an assignment outside of any function.
- The type is `int`.
- The value should not change, so mark it as `const`.

## 2. Calculate the remaining oven time in minutes

- C understands common arithmetic operators: `+`, `-`, `*`, `/`.
- The argument passed to the function can be accessed by name, in this case giving the elapsed time.
- Remember that C functions generally need a `return` keyword (_though `void` functions will be an exception, in later concepts_).

## 3. Calculate the preparation time in minutes

- You can call other functions and use the returned value like variables: `return 22 * myOtherCalculation();`

## 4. Calculate the elapsed time in minutes

- The output should combine the time for the preparation and the time the lasagna has already been in the oven.

