# Introduction

There are various idioomatic ways to solve Raindrops.

## General Guidance

The key to solving Raindrops is to know if the input is evenly divisible by `3`, `5` and/or `7` using the [modulo operator][modulo-operator].

## Assumptions

- `drops` is a non-negative, 32-bit integer (from `0` to `2,147,483,647`).
- `result` has enough space to hold the largest output string, meaning 16 bytes:
  - 15 bytes for `"PlingPlangPlong"`, plus one for the null terminating character;
  - 10 bytes for the largest possible value of `drops`, plus one for `'\0'`.
- `result` has been initialized as an empty string (that is, `result[0]` is `'\0'`).

[modulo-operator]: https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/
