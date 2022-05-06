# Introduction

Functions have external linkage by default and can be called from any other file in the project.
For more on linkage please see the [linkage concept](../linkage/introduction.md#Introduction).
A `static` function can only be called within the source file where it is defined.

For example

```c
// file scope, internal linkage
// can only be called from within this file
static void some_function()
{
    // code snipped
}

// file scope, external linkage by default
// can be called from any other file in the project
int main()
{
    // code snipped
}
```
