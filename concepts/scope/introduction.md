# Introduction

The scope of a value relates to where in the program that value can be accessed.

## The four types of scope: block; function; function prototype; file

### Block scope

A value with block scope can only be accessed from within the block where it is defined.
For more on blocks, please see the [block concept](../blocks/introduction.md#Introduction).

### Function scope

Function scope is a special kind of scope that applies to labels used with `goto` statements.
Two labels with the same name cannot be used in the same function, even if the labels are defined in separate blocks within the function.

### Function prototype scope

Function prototype scope is another special kind of scope that applies only to parameters named within the protoype (also referred to as the declaration, keeping in mind that not all declarations are prototypes.)
A parameter name is usually optional in a function declaration.
The scope of a name is relevant only within the declaration.
A function definition does not have to use the same name for a parameter that was used in the function declaration.

### File scope

A value with file scope can be accessed from anywhere in the file.
Any such a value is defined outside a function.
