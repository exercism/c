# Minesweeper

Add the mine counts to a completed Minesweeper board.

Minesweeper is a popular game where the user has to find the mines using
numeric hints that indicate how many mines are directly adjacent
(horizontally, vertically, diagonally) to a square.

In this exercise you have to create some code that counts the number of
mines adjacent to a given empty square and replaces that square with the
count.

The board is a rectangle composed of blank space (' ') characters. A mine
is represented by an asterisk ('\*') character.

If a given space has no adjacent mines at all, leave that square blank.

## Examples

For example you may receive a 5 x 4 board like this (empty spaces are
represented here with the '·' character for display on screen):

```
·*·*·
··*··
··*··
·····
```

And your code will transform it into this:

```
1*3*1
13*31
·2*2·
·111·
```

## Getting Started

Make sure you have read the "Guides" section of the
[C track][c-track] on the Exercism site. This covers
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

As you progress through the tests, take the time to refactor your
implementation for readability and expressiveness and then go on to the next
test.

Try to use standard C99 facilities in preference to writing your own
low-level algorithms or facilities by hand.

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.

[c-track]: https://exercism.io/my/tracks/c
[3-tdd-rules]: http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd
