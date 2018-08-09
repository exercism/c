# Largest Series Product

Given a string of digits, calculate the largest product for a contiguous
substring of digits of length n.

For example, for the input `'1027839564'`, the largest product for a
series of 3 digits is 270 (9 * 5 * 6), and the largest product for a
series of 5 digits is 7560 (7 * 8 * 3 * 9 * 5).

Note that these series are only required to occupy *adjacent positions*
in the input; the digits need not be *numerically consecutive*.

For the input `'73167176531330624919225119674426574742355349194934'`,
the largest product for a series of 6 digits is 23520.

## Getting Started

Make sure you have read the "Guides" section of the
[C track](https://exercism.io/my/tracks/c) on the Exercism site. This covers
the basic information on setting up the development environment expected
by the exercises.


## Passing the Tests

Get the first test compiling, linking and passing by following the [three
rules of test-driven development][3-tdd-rules].

The included makefile can be used to create and run the tests using the `test`
task.

    make test

Create just the functions you need to satisfy any compiler errors and get the
test to fail. Then write just enough code to get the test to pass. Once you've
done that, move onto the next test.

[3-tdd-rules]: http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd

As you progress through the tests, take the time to refactor your
implementation for readability and expressiveness and then go on to the next
test.

Try to use standard C99 facilities in preference to writing your own
low-level algorithms or facilities by hand.

## Source

A variation on Problem 8 at Project Euler [http://projecteuler.net/problem=8](http://projecteuler.net/problem=8)

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.
