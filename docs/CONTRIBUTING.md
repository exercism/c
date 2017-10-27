# Contributing to the C Track

Thank you for interest in contributing to the Exercism C language track! 
All contributions are welcome, be it a new exercise, a change to the tooling or documentation, a raised issue or even just a commment on an existing issue or PR.
This file provides information to help you get started.

Firstly, have a read of the Exercism [docs repository](https://github.com/exercism/docs), specifically the information on [contributing to a language track](https://github.com/exercism/docs/blob/master/contributing-to-language-tracks/README.md), as these documents cover a lot of the basic information.

Subsequently note that there are a few things specific to this repository that are explained below.

## Coding Style

The exercise code is checked during CI for conformance to a set of style rules. The check uses the GNU `indent` CLI tool.
When adding or making a change to an exercise, you can check that your change conforms to these rules by running the tool locally before commiting.

The style rules used are explained in the [style guide](https://github.com/exercism/c/blob/master/docs/C_STYLE_GUIDE.md#indentation-and-format). 
In short, they equate to the [Linux kernel coding style](https://www.kernel.org/doc/html/latest/process/coding-style.html) with 3 space indents and no tabs.

On linux `indent` should be available for install via your distribution's package manager. 
On a Mac you can install the package `gnu-indent` using [Homebrew](https://brew.sh).

Indent can be run on all files by executing `indent.sh`.
To manually run it on a single file, you can execute:

```bash
indent -linux -i3 -nut $(file)
```

If your system does not support the `-linux` option, you can run the long-form command instead:

```bash
indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1 $(file)
```

## Continuous Integration

The repository uses Travis CI to run some scripts on each commit to a pull request. 
The simplest way to run these scripts on your own contribution is to open a PR on this repository with your changes, mark the title as [WIP] so that maintainers know that it isn't quite ready to be merged just yet and then allow this repository's CI setup to take care of things for you automatically.

### Run CI on Your Own Fork

If you would like, it is also possible to run Travis on your own fork. 
The good folks at fish-shell have [some great information](https://github.com/fish-shell/fish-shell/blob/master/CONTRIBUTING.md#travis-ci-build-and-test) to help you get started with setting up Travis on your own fork.

### Run CI Scripts Locally
You can also run individual scripts on your own machine before commiting. 
Firstly make sure you have the necessary tools installed (such as `indent`, `git`, `sed`, `make`, `valgrind` and a C compiler), and then run the required script from the repoistory root. For example:

```bash
~/git/c$ ./bin/run-tests
```

### What Are the CI Scripts?
You can see from the [.travis.yml](https://github.com/exercism/c/blob/master/.travis.yml) file that Travis is instructed to run scripts from the [`./bin`](https://github.com/exercism/c/tree/master/bin) directory. 
The work these scripts perform is descibed as folows:

- `fetch-configlet` just fetches the `configlet` tool from its [repository](https://github.com/exercism/configlet).

- `configlet` is a tool, specific to Exercism, that performs some repository management tasks. 
The command for `configlet` used by Travis is [`lint`](https://github.com/exercism/configlet/blob/master/README.md#lint). If `configlet` finds any issues Travis will output the details and report a failure on the related PR.

- `verify-indent` runs `indent` and verifies that it did not result in any file changes. 
If the check does result in file changes, Travis will output the details and report a failure on the related PR.

- `run-tests` loops through each exercise, prepares the exercise for building and then builds it using `make` and runs `valgrind`. 
If there are build errors, any test fails or there is a memory leak, Travis will output the details and report a failure on the related PR.

## Exercise anatomy

Each exercise should be contained in a directory `c/exercises/<my exercise>` with `<my exercise>` referring to the name of the exercise. 
The structure of the directory is as follows:

```
+-- <my exercise>
    +-- makefile
    +-- src
    |   +-- example.c
    |   +-- example.h | <my exercise>.h
    +-- test
        +-- test_<my exercise>.c
        +-- vendor
            +-- unity.c
            +-- unity.h
            +-- unity_internals.h
```

* `test` - contains the test file `test_<my exercise>.c` and a `vendor` directory containing the test harness [Unity](http://www.throwtheswitch.org/unity/) from [ThrowTheSwitch](http://www.throwtheswitch.org/#intro-1-section).
ThrowTheSwitch has a decent guide on [getting started with Unity](http://www.throwtheswitch.org/getting-started-with-unity/) should you desire a tutorial. The layout of the test file is described in the [style guide](https://github.com/exercism/c/blob/master/docs/C_STYLE_GUIDE.md#test-file-layout).

* `src` - contains the example files `example.c` and `example.h`. These are both skipped by the `exercism` CLI when downloading to the client, so it is imperative that you do not reference the names of the files in your code. 
If you need to provide a header file example that is necessary to run your tests it should be named `<my exercise>.h` instead.
Please also use [`include`](http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node90.html) guards in your header files. 
The tests can be run using the [`bin/run-tests`](https://github.com/exercism/c/blob/master/bin/run-tests) script which will rename the `example.{c|h}` files accordingly.
