# `if` Statements

**raindrops.h**

```c
#ifndef RAINDROPS_H
#define RAINDROPS_H

void convert(char result[], int drops);

#endif
```

**raindrops.c**

```c
#include "raindrops.h"

#include <stdio.h>
#include <string.h>

void convert(char result[], int drops)
{
   if (drops % 3 == 0)
      strcat(result, "Pling");
   if (drops % 5 == 0)
      strcat(result, "Plang");
   if (drops % 7 == 0)
      strcat(result, "Plong");

   if (strlen(result) == 0)
      sprintf(result, "%d", drops);
}
```

- The first `if` statement checks if `drops` is a multiple of `3`.
  If so, `"Pling"` is concatenated to `result` using the [`strcat` function][strcat].
- The second `if` statement checks if `drops` is a multiple of `5`.
  If so, `"Plang"` is concatenated to `result` using the [`strcat` function][strcat].
- The thrd `if` statement checks if `drops` is a multiple of `7`.
  If so, `"Plong"` is concatenated to `result` using the [`strcat` function][strcat].

Finally, the [`strlen` function] checks if `result` is empty: if so, the [`sprintf` function] formats `drops` as string into `result`.

[strcat]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/strcat.html
[strlen]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/strlen.html
[sprintf]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/sprintf.html
