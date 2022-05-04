# About

Functions have external linkage by default and can be called from any other file in the project.
For more on linkage please see the [linkage concept](../linkage/introduction.md#Introduction).
A `static` function can only be called within the source file where it is defined.

Even if a function is declared in a header, if it is defined as `static` it will not be callable from outside of its source file.
A source file could include the header, call the `static` function declared in the header, and compile, but the linker will fail to find the `static` function definition.
A function marked as `static` in a source file should not be declared in its header file.
