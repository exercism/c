Each exercise supplies the unit tests and a Make build recipe.
You provide the implementation.

Each test file is meant to link against your implementation to provide a console executable that runs the tests.
Running the test executable prints messages for each failing test and reports a non-zero exit status when tests fail.

Working through each exercise is a process of:
* Create the initial build with Make
* For each unit test:
  * Remove the `TEST_IGNORE()` line.
  * Satisfy any compile errors to make the test fail.
  * Implement just enough to make the test pass.
  * Refactor your implementation to enhance readability, reduce duplication, etc.

## Compiling and running the tests

Each exercise will bring a `makefile` file along with the unit tests in the `tests/` directory.
You should not need to edit the Make file.
The provided recipe assumes that your implementation exists as a header file and a source file named after the exercise.

For instance, the exercise `bob` expects an implementation in `src/bob.h` and `src/bob.c`.
For exercises with dashes in their name, the source files are assumed to use underscores, so `word-count` expects `src/word_count.h` and `src/word_count.c`.
You may decide that your implementation is sufficiently simple that it can live entirely in the header, in which case you can omit the `c` file.

**Create your initial implementation files before running Make.**  
If you do not have files `src/bob.h` and `src/bob.c` when running Make for exercise `bob`, then Make will generate an error about files not being found.
**These files can be empty, but they must exist.**

### Build your code

The simplest way to build your code is by using `make` at the command line (CLI).
On Linux the CLI is available in bash or similar, on MacOS use Terminal. 
On Windows 10, the Windows Subsystem for Linux (WSL) Bash is available.
To do this, assuming the current exercise is `bob` and we're in the exercise folder:

```bash
$ touch src/bob.{h,c}
$ make
```

Then to test:

```bash
$ make test
```

#### MacOS Build Alternative
On MacOS you can also use Xcode. 
To build the code select _Build_ from the toolbar.

#### Windows Build Alternatives
On Microsoft Windows 10 the recommended option, as above, is [WSL Bash](https://msdn.microsoft.com/en-us/commandline/wsl/about).
If you are using an earlier version of Windows or WSL Bash is not available to you you can use Microsoft's [Visual Studio](https://www.visualstudio.com/vs/) IDE, which comes with its own compiler. 
Alternatively you could use [MSYS/MinGW](http://www.mingw.org/) (32-bit only) or [mingw6-w64](http://mingw-w64.org/doku.php) (32 & 64-bit)

If using Visual Studio, the easiest way to open an exercise is to start a "Blank Project" from the C project template types.
Then manually add the files from the exercise to it by right clicking on the project in the Solution Explorer and selecting _Add_ > _Existing File_ and selecting each of the .c and .h files within the exercise directory. 
This allows you to build the project by selecting _Build_ > _Build Solution_ from the menu. Then  select _Debug_ > _Start Debugging_ to run it.

Visual Studio can also be made to build the project using the makefile. 
This requires a per exercise configuration. See the documentation on this [here](https://docs.microsoft.com/en-gb/cpp/ide/non-msbuild-projects).
