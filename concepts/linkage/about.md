# About

Linkage describes from where in the code an identifier may be accessed.
Values with block, function, or function prototype scope have no linkage.
This means they can't be accessed from outside their scope.
For more on scope please see the [scope concept](../scope/introduction.md#Introduction).

## External linkage

Identifiers with file scope have external linkage by default.
An identifier with external linkage can be called from any file in the program.

## Internal linkage

An identifier with file scope can be made to have internal linkage by using the `static` specifier.
An identifier with internal linkage can only be used within its file.

For example

```c
int public_count = 0; // file scope, external linkage by default
static int private_count = 0;  // file scope, internal linkage 

// file scope, internal linkage
static void some_function()
{
    // code snipped
}

// file scope, external linkage by default
int main()
{
    // code snipped
}
```

Static linkage should not be confused with static storage duration.
For more on static storage duration, please see the [storage duration concept](https://github.com/exercism/c/blob/main/concepts/storage-class-specifiers/about.md#static-the-storage-specifier-not-to-be-confused-with-the-static-linkage-type).

If a value (as opposed to a function) is declared in a header but is defined in the source file as a `static` file-scoped identifier with an initialized value, it's initialized value will not be accessible from outside of its source file.
It may compile and link and run without an error, but the value will be the zero value for the identifier, even if the value is declared with `extern`.
(For more on `extern` please see the [extern concept](https://github.com/exercism/c/blob/main/concepts/storage-class-specifiers/about.md#extern-how-to-access-a-variable-in-another-translation-unit).)
A file-scoped identifier marked as `static` in a source file should not be declared in its header file.
