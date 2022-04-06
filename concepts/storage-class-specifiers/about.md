# About

Storage-class specifiers relate to how variables are stored in memory.
They are closely related to the storage duration (also referred to as the lifetime) of a value.

## auto (the default storage class for variables)

Since variables defined within a block or function are `auto` by default, it is not common to explicitly use the term.
Another reason that `auto` is often avoided is because it has a different meaning in C++.
Codebases that combine C and C++ may be less confusing by avoiding the `auto` storage specifier.
An `auto` variable's lifetime begins when its block is entered and ends when its block is exited.
An `auto` variable has memory allocated for it, _but with no default value_, when its block is entered.
An exception is for variable length arrays (VLAs.)
A VLA's allocation happens where it is declared or defined in its block and ends when its block is exited.
An `auto` variable can be intialized by any valid expression.


## static (the storage specifier not to be confused with the static linkage type)


