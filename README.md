# C [![Build Status](https://travis-ci.org/exercism/c.svg?branch=master)](https://travis-ci.org/exercism/c)

Exercism problems in C

## Hacktoberfest

If you would like to contribute to this repository as part of [hacktoberfest](https://github.com/blog/2452-get-started-with-hacktoberfest), please read the rest of this (short) readme, then jump in!

This C language track of exercism is nearly ready to graduate from "upcoming" to "available". 
To that aim the repository has several issues marked with labels such as 'help wanted', 'good first patch' or 'hacktoberfest'. 
Issues marked with these labels are a good place to start contributing - you are welcome to contribute to any of these, any other issue, or even submit your own issues or pull requests.

To get an idea of the general status in relation to the launch of the track, check out [issue #8](https://github.com/exercism/c/issues/8)

## Contributing Guide

Please see the [Exercism contributing guide](https://github.com/exercism/docs/blob/master/contributing-to-language-tracks/README.md) for general contribution tips.

## Coding Style

All test and example code should be written using the [Linux kernel coding style](https://www.kernel.org/doc/html/latest/process/coding-style.html) with 3 space indents and no tabs.

If GNU `indent` is installed, this can be run on all files by executing `indent.sh`. On a Mac you can install the package `gnu-indent` using [Homebrew](http://brew.sh).

To manually run it on a single file, you can execute:

```shell
indent -linux -i3 -nut $(file)
```

If your system does not support the `-linux` option, you can run the long form command instead:

```shell
indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1 $(file)
```

See the [GNU `indent` manual](https://www.gnu.org/software/indent/manual/indent.html#SEC4) for more information.

## Exercise Anatomy

Each exercise should be contained in a directory ```c/exercises/<my exercise>``` with ```<my exercise>``` referring to the name of the exercise.  The structure of the directory is as follows:

```
+-- <my exercise>
    +-- makefile
    +-- src
    |   +-- example.c
    |   +-- example.h | <my exercise>.h
    +-- test
        +-- test_<my exercise>.c
        +-- vendor
            +-- unity.c
            +-- unity.h
            +-- unity_internals.h
```

* `test` - contains the test file ```test_<my exercise>.c``` and a ```vendor``` directory containing the test harness [Unity](http://www.throwtheswitch.org/unity/) from [ThrowTheSwitch](http://www.throwtheswitch.org/#intro-1-section).  ThrowTheSwitch has a decent guide on [getting started with Unity](http://www.throwtheswitch.org/getting-started-with-unity/) should you desire a tutorial.

* `src` - contains the example files ```example.c``` and ```example.h```. These are both skipped by the ```exercism``` cli when downloading to the client, so it is imperative that you do not reference the names of the files in your code. If you need to provide a header file example that is necessary to run your tests it should be named ```<my exercise>.h``` instead.  Please also use [```include```](http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node90.html) guards in your header files. The tests can be run using the [```bin/run-tests```](https://github.com/exercism/c/blob/master/bin/run-tests) script which will rename the ```example.{c|h}``` files accordingly.

## License

The MIT License (MIT)

Copyright (c) 2014 Katrina Owen, _@kytrinyx.com
