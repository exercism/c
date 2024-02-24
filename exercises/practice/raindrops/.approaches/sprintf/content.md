## `sprintf` Function

**raindrops.h**

```c
#ifndef RAINDROPS_H
#define RAINDROPS_H

char *convert(char result[], int drops);

#endif
```

**raindrops.c**

```c
#include "raindrops.h"

#include <stdio.h>
#include <string.h>

#include "raindrops.h"

#include <stdio.h>
#include <string.h>

char *convert(char result[], int drops)
{
   sprintf(result, "%s%s%s", drops % 3 == 0 ? "Pling" : "",
           drops % 5 == 0 ? "Plang" : "", drops % 7 == 0 ? "Plong" : "");

   if (strlen(result) == 0)
      sprintf(result, "%d", drops);

   return result;
}
```

This approach allows for very concise, if not a bit obfuscated, code.

A series of [ternary conditional operators][conditional-operator] check if `drops` is a multiple of `3`, `5`, or `7` respectively.
If it is, the expression returns the appropriate raindrop sound (either `"Pling"`, `"Plang"` or `"Plong"`); otherwise, the result is the empty string (`""`).

Then, in the same statement, a single call to the [`sprintf` function][sprintf] concatenates all the above three strings.

Finally, the [`strlen` function][strlen] checks if `result` is empty: if so, `sprintf` is used again to format `drops` as string into `result`.

[conditional-operator]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c/
[sprintf]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/sprintf.html
[strlen]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/strlen.html
