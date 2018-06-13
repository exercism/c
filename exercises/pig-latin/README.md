Implement a program that translates from English to Pig Latin.

Pig Latin is a made-up children's language that's intended to be
confusing. It obeys a few simple rules (below), but when it's spoken
quickly it's really difficult for non-children (and non-native speakers)
to understand.

- **Rule 1**: If a word begins with a vowel sound, add an "ay" sound to the end of the word. Please note that "xr" and "yt" at the beginning of a word make vowel sounds (e.g. "xray" -> "xrayay", "yttria" -> "yttriaay").
- **Rule 2**: If a word begins with a consonant sound, move it to the end of the word and then add an "ay" sound to the end of the word. Consonant sounds can be made up of multiple consonants, a.k.a. a consonant cluster (e.g. "chair" -> "airchay").
- **Rule 3**: If a word starts with a consonant sound followed by "qu", move it to the end of the word, and then add an "ay" sound to the end of the word (e.g. "square" -> "aresquay").
- **Rule 4**: If a word contains a "y" after a consonant cluster or as the second letter in a two letter word it makes a vowel sound (e.g. "rhythm" -> "ythmrhay", "my" -> "ymay").

There are a few more rules for edge cases, and there are regional
variants too.

See <http://en.wikipedia.org/wiki/Pig_latin> for more details.

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

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.
