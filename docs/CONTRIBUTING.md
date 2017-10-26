# Contributing to the C Track

Thank you for interest in contributing to the Exercism C language track! 
All contributions are welcome, be it a new exercise, a change to the tooling or documentation, a raised issue or even just a commment on an existing issue or PR.
This file provides information to help you get started.

Firstly, have a read of the Exercism [docs repository](https://github.com/exercism/docs), specifically the information on [contributing to a language track](https://github.com/exercism/docs/blob/master/contributing-to-language-tracks/README.md), as these documents covers a lot of the basic information.

Subsequently there are a few things specific to this repository that are explained below.

## Coding Style

The exercise code is checked during CI for conformance to a set of style rules. The check uses the GNU indent CLI tool.
When adding or making a change to an exercise, you can check your change conforms to these rules by running the tool locally.

The style rules used are explained in the [style guide](https://github.com/exercism/c/blob/master/docs/C_STYLE_GUIDE.md). 
In short, they equate to the [Linux kernel coding style](https://www.kernel.org/doc/html/latest/process/coding-style.html) with 3 space indents and no tabs.

To install the tool, please see the [install indent guide](#).

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

**TODO: THE TRAVIS CHECKS AND HOW TO RUN THEM LOCALLY**

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
ThrowTheSwitch has a decent guide on [getting started with Unity](http://www.throwtheswitch.org/getting-started-with-unity/) should you desire a tutorial.

* `src` - contains the example files `example.c` and `example.h`. These are both skipped by the `exercism` CLI when downloading to the client, so it is imperative that you do not reference the names of the files in your code. 
If you need to provide a header file example that is necessary to run your tests it should be named `<my exercise>.h` instead.
Please also use [`include`](http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node90.html) guards in your header files. 
The tests can be run using the [`bin/run-tests`](https://github.com/exercism/c/blob/master/bin/run-tests) script which will rename the `example.{c|h}` files accordingly.
