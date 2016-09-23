# xC [![Build Status](https://travis-ci.org/exercism/xc.svg?branch=master)](https://travis-ci.org/exercism/xc)

Exercism problems in C

## Contributing Guide

Please see the [Exercism contributing guide](https://github.com/exercism/x-common/blob/master/CONTRIBUTING.md) for general contribution tips.

## Coding Style

All test and example code should be written using the [Linux kernel coding style](https://www.kernel.org/doc/Documentation/CodingStyle) with 3 space indents.

If GNU `indent` is installed, this can be run on all files by executing `indent.sh`.

To run it on a single file, you can execute:

```shell
indent -linux -i3 $(file)
```

If your system does not support the `-linux` option, you can run the long form command instead:

```shell
indent -nbad -bap -nbc -bbo -hnl -br -brs -c33 -cd33 -ncdb -ce -ci4 -cli0 -d0 -di1 -nfc1 -i3 -nut -ip0 -l80 -lp -npcs -nprs -npsl -sai -saf -saw -ncs -nsc -sob -nfca -cp33 -ss -il1 $(file)
```

See the [GNU `indent` manual](https://www.gnu.org/software/indent/manual/indent.html#SEC4) for more information.

## License

The MIT License (MIT)

Copyright (c) 2014 Katrina Owen, _@kytrinyx.com
