# Introduction

There are several ways to solve Clock.
One approach is to minimize duplication of code.

## General guidance

If you have solved Clock in another language, you may have discovered how the logic for calculation may possibly be simplified by storing only minutes in the Clock type.
That leaves [separating the concern][separating the concern] of hours and minutes only for representing the Clock as a string,
which is the only place that cares about it.
However, this is not possible on the C track, because the tests use struct literals which only have an initializer for the `text` field,
so having a `minutes` field is not possible at the time of writing.

Instead of using `60`, `24` or `1440` literals as [magic numbers][magic numbers],
it might be considered to define them as [constants][const] with meaningful names.

Another concern is to minimize duplicate code between the `clock_create`, `clock_add` and `clock_subtract` functions,
thus keeping the code [DRY](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself).

Finally, for `clock_add` and `clock_subtract`, consider returning a new `clock_t` struct instead of mutating the existing `clock_t`.
For the benefits of immutability in general, see [this article][immutability-benefits].

## Approach: Minimize duplicate code

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

static void set_text(clock_t *clock, int all_minutes)
{
   int hours = all_minutes / 60;
   int minutes = all_minutes % 60;
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

For more information, check the [Minimize duplicate code approach][approach-minimize-duplicate-code].

[approach-minimize-duplicate-code]: https://exercism.org/tracks/c/exercises/clock/approaches/minimize-duplicate-code
[separating the concern]: https://en.wikipedia.org/wiki/Separation_of_concerns
[magic numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
[const]: [https://go.dev/tour/basics/15](https://www.geeksforgeeks.org/const-qualifier-in-c/)
[DRY]: https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
[immutability-benefits]: https://hackernoon.com/5-benefits-of-immutable-objects-worth-considering-for-your-next-project-f98e7e85b6ac
