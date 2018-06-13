# Wordy

Parse and evaluate simple math word problems returning the answer as an integer.

## Iteration 1 — Addition

Add two numbers together.

> What is 5 plus 13?

Evaluates to 18.

Handle large numbers and negative numbers.

## Iteration 2 — Subtraction, Multiplication and Division

Now, perform the other three operations.

> What is 7 minus 5?

2

> What is 6 multiplied by 4?

24

> What is 25 divided by 5?

5

## Iteration 3 — Multiple Operations

Handle a set of operations, in sequence.

Since these are verbal word problems, evaluate the expression from
left-to-right, _ignoring the typical order of operations._

> What is 5 plus 13 plus 6?

24

> What is 3 plus 2 multiplied by 3?

15  (i.e. not 9)

## Bonus — Exponentials

If you'd like, handle exponentials.

> What is 2 raised to the 5th power?

32

## Getting Started

Make sure you have read the
[C page](http://exercism.io/languages/c) on the Exercism site. This covers
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

Inspired by one of the generated questions in the Extreme Startup game. [https://github.com/rchatley/extreme_startup](https://github.com/rchatley/extreme_startup)

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.
