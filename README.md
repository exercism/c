# xC [![Build Status](https://travis-ci.org/exercism/xc.svg?branch=master)](https://travis-ci.org/exercism/xc)

Exercism problems in C

## Contributing Guide

Please see the [Exercism contributing guide](https://github.com/exercism/x-common/blob/master/CONTRIBUTING.md) for general contribution tips.

## Coding Style

All test and example code should be written using the [Linux kernel coding style](https://www.kernel.org/doc/Documentation/CodingStyle) with 3 space indents and no tabs.

If GNU `indent` is installed, this can be run on all files by executing `indent.sh`.

To run it on a single file, you can execute:

```shell
indent -linux -i3 -nut $(file)
```

If your system does not support the `-linux` option, you can run the long form command instead:

```shell
indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1 $(file)
```

See the [GNU `indent` manual](https://www.gnu.org/software/indent/manual/indent.html#SEC4) for more information.

## Example Solutions

As stated in the [contributing guide](https://github.com/exercism/x-common/blob/master/CONTRIBUTING.md#track-anatomy), each exercise should have an example solution that passes all of the given tests.

The example source and header files should be named `example.c` and `example.h`, respectively. If a header file template is needed, the file should be named after the exercise, instead of `example.h`. For example, if a typedef is used within the tests for the `anagram` exercise, it should be defined in `anagram.h` alongside the `example.c` file; in this case, no `example.h` file would exist.

## License

The MIT License (MIT)

Copyright (c) 2014 Katrina Owen, _@kytrinyx.com
