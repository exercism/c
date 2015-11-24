Each exercise supplies the unit tests and a Make build recipe.  You
provide the implementation.

Each test file is meant to link against your implementation to provide a
console executable that runs the tests.  Running the test executable
prints messages for each failing test and reports a non-zero exit status
when tests fail.

Working through each exercise is a process of:
* Creating the initial build with Make
* For each unit test:
 * Satisfy compile errors to make the test fail.
 * Implement just enough to make the test pass.
 * Refactor your implementation to enhance readability, reduce duplication,
   etc.
 * Uncomment the next test


### Compiling and running the tests

Each exercise will bring a `makefile` file along with the unit
tests in the `tests/` directory.  You should not need to edit the Make file.
The provided recipe assumes that your implementation exists as a header file
and a source file named after the exercise.

For instance, the exercise `bob` expects an implementation in `src/bob.h`
and `src/bob.c`.  For exercises with dashes in their name, the source
files are assumed to use underscores, so `word-count` expects
`src/word_count.h` and `src/word_count.c`.  You may decide that your
impementation is sufficiently simple that it can live entirely in the
header, in which case you can omit the `cpp` file.

**Create your initial implementation files before running Make.**  If
you do not have files `src/bob.h` and `src/bob.c` when running
Make for exercise `bob`, then Make will generate an error about files
not being found.  **These files can be empty, but they must exist.**

You can build your code using the appropriate command for your environment:

* Linux with make: `make`
* Windows with Visual Studio 2013: Select Build / Build Solution from the menu.
* MacOS with Xcode: Select Build from the toolbar


#### Testing on Linux or MacOS with make

Assuming the current exercise is `bob` and we're in the exercise folder:

```
$ touch src/bob.{h,cpp}
$ make test
```


#### Testing on Windows with Visual Studio 2013

?


#### Testing on MacOS with Xcode

?
