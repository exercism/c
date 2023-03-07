# Introduction

There are various wys to solve Secret Handshake.
One approach is to iterate once even if the actions are meant to be reversed.

## Approach: Iterate once

**secret_handshake.h**
```c
#ifndef SECRET_HANDSHAKE_H
#define SECRET_HANDSHAKE_H

#include <stddef.h>

const char **commands(size_t number);

#endif
```

**secret_handshake.c**

```c
#include "secret_handshake.h"
#include <malloc.h>

static const char * signals[] = { "wink", "double blink", "close your eyes", "jump" };

const char **commands(size_t n) {
    const char **output = calloc(4, sizeof(char *));
    int signal = 0, signal_incr = 1, output_idx = 0, end = 4;
    if (n & 16) {signal = 3; signal_incr = -1; end = -1;}

    for (; signal != end; signal+=signal_incr)
        if (n & 1 << signal)
            output[output_idx++] = signals[signal];
    return output;
}
```

For more information, check the [Iterate once approach][approach-iterate-once].

[approach-iterate-once]: https://exercism.org/tracks/c/exercises/secret-handshake/approaches/iterate-once
