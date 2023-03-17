# Minimize duplicate code

**clock.h**

```c
#include <stdbool.h>

#define MAX_STR_LEN 6 // "##:##\0"

typedef struct
{
   char text[MAX_STR_LEN];
} clock_t;

clock_t clock_create(int hour, int minute);
clock_t clock_add(clock_t clock, int minute_add);
clock_t clock_subtract(clock_t clock, int minute_subtract);
bool clock_is_equal(clock_t a, clock_t b);

#endif
```

**clock.c**

```c
#include "clock.h"
#include <stdio.h>
#include <string.h>
const int DAY_MINUTES = 1440;
const int HOUR_MINUTES = 60;

static int normalize_minutes(int minutes)
{
   return (minutes < 0) ? DAY_MINUTES + (minutes % DAY_MINUTES)
                        : minutes % DAY_MINUTES;
}

static void set_text(clock_t *clock, int allMinutes)
{
   int hours = allMinutes / 60;
   int minutes = allMinutes % 60;
   sprintf(clock->text, "%02d:%02d", hours, minutes);
}

static int minutes_from_text(char text[static 5])
{
   int hour, minute;
   sscanf(text, "%d:%d", &hour, &minute);
   return (hour * HOUR_MINUTES) + minute;
}

clock_t clock_create(int hour, int minute)
{
   clock_t clock;
   set_text(&clock, normalize_minutes((hour * 60) + minute));
   return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
   return clock_create(0, minutes_from_text(clock.text) + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
   return clock_create(0, minutes_from_text(clock.text) - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b)
{
   return (!strcmp(a.text, b.text));
}
```

This approach starts by defining some [`const`][const] values for the amount of minutes in a day and the amount of minutes in an hour.
The `const` values are given meaningful names instead of using the integer literals as [magic numbers][magic-numbers].

The `normalize_minutes` function uses a [ternary operator][ternary] to handle rollover past midnight for either positive or negative values.
If the minutes are ngative, the statement uses the [modulo operator][modulo-operator] (`%`) to return the result of handling negative minutes.

- For example, if the minutes is `-1500`, which rolls over past midnight in the negative direction, `DAY_MINUTES` (`1440`) added by
the remainder of `-1500` divided by `DAY_MINUTES` (`1500` % `1440` = `-60`) is `1380`.

Otherwise the statement uses the modulo operator (`%`) to return the result of handling positive minutes.

- For example, if the minutes is `1500`, which rolls over past midnight in the positive direction, the remainder of `1500`
divided by `DAY_MINUTES` (`1440`)  is `60`.

The `set_text` function takes the `char` array of the Clock `text`.
It uses [`[static 5]`][static-5] to constrain the array to having no more than five elements.

[magic-numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
[const]: [https://go.dev/tour/basics/15](https://www.geeksforgeeks.org/const-qualifier-in-c/)
[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
[modulo-operator]: https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/
[static-5]: https://stackoverflow.com/questions/3430315/what-is-the-purpose-of-static-keyword-in-array-parameter-of-function-like-char
[DRY]: https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
[immutability-benefits]: https://hackernoon.com/5-benefits-of-immutable-objects-worth-considering-for-your-next-project-f98e7e85b6ac
