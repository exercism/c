# Data-Driven Programming

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

typedef struct {
   int factor;
   const char *sound;
} sound_t;

static const sound_t SOUNDS[] = {
   { 3, "Pling" },
   { 5, "Plang" },
   { 7, "Plong" },
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void convert(char result[], int drops)
{
   for (size_t i = 0; i < ARRAY_SIZE(SOUNDS); i++) {
      if (drops % SOUNDS[i].factor == 0) {
         strcat(result, SOUNDS[i].sound);
      }
   }

   if (strlen(result) == 0) {
      sprintf(result, "%d", drops);
   }
}
```

First, the program defines a [structure][struct] [data type][typedef] to hold together two pieces of information: a factor and its corresponding sound.
Then, an array is created to hold all the necessary data, which is used to drive the logc of the program.

The body of the function does not have any knowledge of the actual data, becoming simple and flexible:

- For each element of the `SOUNDS` array
-- If the given number is a multiple of the current `factor`
--- Then concatenate the current `sound` to the result string using the [`strcat` function][strcat].

This approach allows for extensible code: for example, new sounds could be added (or removed) without modifying the `convert` function.

Finally, the [`strlen` function] checks if `result` is empty: if so, the [`sprintf` function] formats `drops` as string into `result`.

[struct]: https://www.geeksforgeeks.org/structures-c/
[typedef]: https://www.geeksforgeeks.org/typedef-in-c/
[strcat]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/strcat.html
[strlen]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/strlen.html
[sprintf]: https://pubs.opengroup.org/onlinepubs/9699919799/functions/sprintf.html
