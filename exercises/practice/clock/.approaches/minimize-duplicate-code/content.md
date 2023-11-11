# Minimize duplicate code

**clock.h**

```c
#include <stdbool.h>

#define MAX_STR_LEN sizeof("##:##")

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

The header defines the maximum length of the Clock struct `text` to be `14`.
In practice, six bytes would suffice for `2` hour digits, a colon, `2` minute digits and the null terminating character,
however, when setting the `text`, some compilers realize that `int` values could be large enough so that the null terminating character
could be written past the end of the `text`, unless it is made to be at least fourteen bytes.

This approach starts by defining some [`const`][const] values for the amount of minutes in a day and the amount of minutes in an hour.
The `const` values are given meaningful names instead of using the integer literals as [magic numbers][magic-numbers].

```c
const int DAY_MINUTES = 1440;
const int HOUR_MINUTES = 60;

static int normalize_minutes(int minutes)
{
   return (minutes < 0) ? DAY_MINUTES + (minutes % DAY_MINUTES)
                        : minutes % DAY_MINUTES;
}
```

The `normalize_minutes` function uses a [ternary operator][ternary] to handle rollover past midnight for either positive or negative values.
If the minutes are ngative, the statement uses the [modulo operator][modulo-operator] (`%`) to return the result of handling negative minutes.

- For example, if the minutes is `-1500`, which rolls over past midnight in the negative direction, `DAY_MINUTES` (`1440`) added by
the remainder of `-1500` divided by `DAY_MINUTES` (`1500` % `1440` = `-60`) is `1380`.

Otherwise the statement uses the modulo operator (`%`) to return the result of handling positive minutes.

- For example, if the minutes is `1500`, which rolls over past midnight in the positive direction, the remainder of `1500`
divided by `DAY_MINUTES` (`1440`)  is `60`.

The `set_text` function takes a pointer to a Clock and the minutes.
The [`sprintf`][sprintf] function is used to set the Clock `text`  from the minutes.

```c
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
```

The `minutes_from_text` function takes the `char` array of the Clock `text`.
It uses [`[static 5]`][static-5] to constrain the `text` array to having no more than five elements.
The [sscanf][sscanf] function is used to parse out the `hour` and `minute` values from the `text` into variables.
The function returns the amount of total minutes from the `hour` and `minute` variables.

The `clock_create` function takes the `hour` and `minute` values and uses the `set_text` function to set the `text` field
of a new Clock struct from the normalized total minutes from the `hour` and `minute`.
After creating and setting the Clock struct, it returns the struct.

```c
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
```

The `clock_add` and `clock_subtract` functions both take in a Clock struct and a `minute` value and return the result of calling the `clock_create` function.

- The `clock_add` function passes in `0` for the hour and adds the `minute` value to the value returned from passing in the Clock struct
to the `minutes_from_text` function.
- The `clock_subtract` function passes in `0` for the hour and subtracts the `minute` value from the value returned from passing in the Clock struct
to the `minutes_from_text` function.

Having `clock_add` and `clock_subtract` use the `clock_create` function is a way to keep the code [DRY][DRY].

```c
bool clock_is_equal(clock_t a, clock_t b)
{
   return (!strcmp(a.text, b.text));
}
```
The `clock_is_equal` function uses the [`strcmp`][strcmp] function to return the result of comparing the `text` fields of the two passed-in Clock structs.
It uses the falsiness of `0` and the [logical NOT operator][logical-not] (`!`) to return `true` if `strcmp` returns `0`, meaning there is no difference
between the two strings.

[magic-numbers]: https://en.wikipedia.org/wiki/Magic_number_(programming)
[const]: https://www.geeksforgeeks.org/const-qualifier-in-c/
[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
[modulo-operator]: https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/
[static-5]: https://stackoverflow.com/questions/3430315/what-is-the-purpose-of-static-keyword-in-array-parameter-of-function-like-char
[sprintf]: https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
[sscanf]: https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm
[strcmp]: https://www.geeksforgeeks.org/strcmp-in-c/
[DRY]: https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
[logical-not]: https://www.geeksforgeeks.org/logical-not-operator-in-c-with-examples/
