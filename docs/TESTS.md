# Tests

Each exercise supplies the unit tests and a Make build recipe.
You provide the implementation.

Each test file is meant to link against your implementation to provide a console executable that runs the tests.
Running the test executable prints messages for each failing test and reports a non-zero exit status when tests fail.

To work through an exercise:

* Create the initial build with Make
* For each unit test:
  * Remove the `TEST_IGNORE()` line.
  * Satisfy any compile errors to make the test fail.
  * Implement just enough to make the test pass.
  * Refactor your implementation to enhance readability, reduce duplication, etc.

## Compiling and running the tests

Each exercise will bring a `makefile` file along with a `.c` with the unit tests.
You should not need to edit the Make file.
The provided Make file assumes that your implementation exists as a header file (`.h`) and a source file (`.c`) named after the exercise.

For instance, the exercise `bob` expects an implementation in `bob.h` and `bob.c`.
For exercises with dashes in their name, the source files are assumed to use underscores, so `word-count` expects `word_count.h` and `word_count.c`.
You may decide that your implementation is sufficiently simple that it can live entirely in the header, in which case you can omit the `.c` file.

**Create your initial implementation files before running Make.**
If you do not have files `bob.h` and `bob.c` when running Make for exercise `bob`, then Make will generate an error about files not being found.
**These files can be empty, but they must exist.**

### Build your code

The simplest way to build your code is by using `make` at the command line (CLI).
On Linux the CLI is available in bash or similar, on MacOS use Terminal.
On Windows 10, the Windows Subsystem for Linux (WSL) Bash is available.

To do this, assuming the current directory is the exercise folder:

```console
$ make
```

This will compile your code, and run the tests.

The `makefile` comes also with a build that checks some common mistakes regarding memory leaks and out of bound access to arrays. To run these checks, use the following at the command line:

```console
$ make memcheck
```

### Clean up

To clean up after a build, you can tell `make` to delete all of the build output, including the executable:

```console
$ make clean
```

#### MacOS Build Alternative

On MacOS you can also use Xcode.
To build the code select _Build_ from the toolbar.
