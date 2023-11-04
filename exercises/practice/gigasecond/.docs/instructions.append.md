## Use UTC

To solve this problem, you'll need to convert a `time_t` value into a `struct tm` value.
The [`time.h`][time.h] library gives you two functions to do this.
Make sure you use the one that results in a calendar time expressed in **UTC**.

[time.h]: https://en.cppreference.com/w/c/chrono
