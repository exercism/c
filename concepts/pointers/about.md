# About

A pointer is a variable or constant whose value is the address of another variable or constant.
Pointers are a powerful and potentially dangerous feature of C.
It can be challenging to understand pointers.

```c
int i = 5;
```

When we assign a value to a variable we can then ask two questions.

Who are you?

_I am `i`_.

What do you have?

_I have the integer `5`_.

There is also a third question we can ask.

Where are you?

_I am at `0x6dfed4`_.

Wait, what?

Variables and constants store their value in a memory location.
That location in memory is known as the address of the variable or constant.

## Address operator

To get the address of a variable we use the address operator, which is `&`.
```c
int i = 5;
int *i_address = &i;
```

Wait, what does that `*` mean before `i_address`? Doesn't that mean multiply?

A type followed by a `*` followed by an identifier is the way to declare a pointer to a variable of that type.

Okay, but why make a variable just to hold the address of another variable? 

Why do we care what the address of a variable is in the first place?

Well, we care where variables are when they are in an array.

## Arrays and Pointers

When we create an array like so

```c
int my_ints[] = {1, 2};
```

The value of `my_ints` is actually its address, which also happens to be the same as the address of its first element. The address of its second element will be the first element's address plus the size of an `int` on the system.

To better see this, try running the following

```c
#include <stdio.h>

int main() {
    // my_int's value is its address
    int my_ints[] = {1, 2};
    
    // since my_ints is already an address
    // we don't need the address operator to make a pointer from it.
    // a pointer to my_ints holds the address of my_ints
    int *my_ptr = my_ints;
    
    // the address of my_ints and the value of my_ptr are the same
    printf("my_ints is %p. my_ptr is %p.\n", my_ints, my_ptr);
    
    // both addresses of the first element are the same as the original addresses
    printf("&my_ints[0] is %p. my_ptr + 0 is %p.\n", &my_ints[0], my_ptr + 0);
    
    // both addresses for the second element have increased by the size of an int
    printf("&my_ints[1] is %p. my_ptr + 1 is %p.\n", &my_ints[1], my_ptr + 1); // 
    
    return 0;
}
```

## Pointer Arithmetic, or Why Array Indexes begin at 0

The previous example shows why array indexing begins at `0` instead of `1`.
The index into an array multiplies the index by the size of the type and adds it to the starting address of the array.
Since the first element aligns with the beginning of the array, we multiply the type by zero for adding to the start address to get the first element.
To get the second element we multiple the type by 1 for adding to the start address.
If the type is four bytes in length, the address of the second element will be four bytes higher than the first element.

This is also why pointers are declared to be of a certain type.
If a pointer did not know what type it points to, it would not know how many bytes to advance when adding `1` to it.
Adding `1` to a pointer does not necessariy mean we're adding one byte to the address.
It means we're adding `1` times the length of its type in bytes.

But wait, there's more! You didn't think we were finished with `*`, did you?

## Dereference Operator

Now that we understand how addresses work with array indexing, what good is it if we don't get the value stored at an address?
How do we do that?
To get the value stored at an address we use the dereference operator, which is, you guessed it, `*`.

Come on!
Are you kidding me?
How many uses are there for `*`?!
Multiplication, declaring a pointer, and now derefencing!
It's confusing!
And what exactly is dereferencing, anyway?

An example shows how to use the dereferencing operator

```c
#include <stdio.h>

int main() {
    // define the variable
    int my_ints[] = {1, 2};
    
    // define the pointer from the address of the variable
    int *my_ptr = my_ints;
    
    // prints: my_ints[0] is 1. *(my_ptr + 0) is 1.
    printf("my_ints[0] is %u. *(my_ptr + 0) is %u.\n", my_ints[0], *(my_ptr + 0));
    
    // prints: my_ints[1] is 2. *(my_ptr + 1) is 2.
    printf("my_ints[1] is %u. *(my_ptr + 1) is %u.\n", my_ints[1], *(my_ptr + 1));
    
    return 0;
}
```

Using parentheses can help remove ambiguity of intentions when using pointer arthimetic.
The following example may not print what the programmer intended to

```c
#include <stdio.h>

int main() {
    int my_ints[] = {1, 42};
    int *my_ptr = my_ints;
    
    // prints: my_ints[0] is 1. *++my_ptr is 42.
    printf("my_ints[0] is %u. *++my_ptr is %u.\n", my_ints[0], *++my_ptr);
    
    // prints: my_ints[1] is 43. ++*my_ptr++ is 43.
    printf("my_ints[1] is %u. ++*my_ptr++ is %u.\n", my_ints[1], ++*my_ptr);

    return 0;
}
```

Both the `*` and `++` have the same precedence, but they evaluate from right to left.
In the first line `my_ptr` is first incremented to the second element, which is then dereferenced.
In the second line `my_ptr`, which was incremented to the second element in the first line, is first dereferenced, and then the dereferenced value is incremented.
If we add this line to the above example

```c
// prints: my_ints[1] is 43. *++my_ptr is (some garbage value).
printf("my_ints[1] is %u. *++my_ptr is %u.\n", my_ints[1], *++my_ptr);
```

In that line we have incremented the pointer to be beyond the array.
We have overrun the array and we are pointing at the next four bytes in memory which the pointer interprets as an `int`, but, in fact, those bytes could belong to another variable or variables.
Those four bytes could  be part of a `double` or they could be four `char`s.
The problem is we shouldn't even be looking at them with our pointer.

We could have used

```c
// prints: my_ints[2] is (some garbage value).
printf("my_ints[2] is %u", my_ints[2]);
```

Since array indexing is implemented with a pointer, the same danger of overunning the array applies.

And, since a string is an array of `char`s, pointers can be used with strings, too.
A string is often declared using pointer syntax, like so

```c
char *my_string = "This is my string";
// instead of
// char my_string[] = "This is my string";
```

One question, though.
Why do we put the star next to the identifier?
Why not put it next to the type, since it's a pointer to that type?
Because this

```c
int* my_ptr1, my_ptr2_that_is_really_an_int;
```

does not declare two pointers to an int, but declares a pointer to an int, and an int.
To declare two pointers to an int would be like so

```c
int *my_ptr1, *my_ptr2;
```

So it's good to put the `*` near the identifier to minimize ambiguity.
Or declare only one identifier per line.
And, if you haven't had enough of `*`, welcome to...

## Pointer to Pointers

It is common to see arrays of strings represented like so

```c
#include <stdio.h>

void print_strings(char **passed_in_strings) {
    printf("%s\n", *passed_in_strings);
    printf("%s\n", *(passed_in_strings + 1));
}

int main() {
    char *my_strings[] = {"One string", "Two string"};
    print_strings(my_strings);
    return 0;
}
```

It may not be obvious, but the array of strings is declared and initialized as a pointer to an array of `char` arrays.
When the array of `char` arrays is passed into `print_strings()`, the signature describes it as a pointer to pointer(s) to `char`.

So how do we know that `char **` is really a pointer to an array of pointers to char arrays, and not a pointer to a pointer of a single char?
We don't.
This is one of the may things that can make using pointers confusing.
The following may compile

```c
#include <stdio.h>

void print_strings(char **passed_in_strings) {
    // prints: A (followed by gibberish)
    printf("%s\n", *passed_in_strings);
    // prints gibberish
    printf("%s\n", *(passed_in_strings + 1));
}

int main() {
    char my_char = 'A';
    char *my_ptr = &my_char;
    char **my_ptr_to_ptr = &my_ptr;
    print_strings(my_ptr_to_ptr);
    return 0;
}
```

But `print_strings()` is not being used as intended.
Using a different signature doesn't help. Changing the signature to this

```c
void print_strings(char *passed_in_strings[]) {
```

may still compile and still print gibberish.
But there is really no value to passing in a pointer to a pointer to a single char.
Chances are, when you see `char **`, it represents a pointer to to an array of pointers to char arrays.

We've seen a pointer passed into a function.
But why pass a pointer into a function?

## Passing a Pointer to a Function

In C, arguments are passed to functions by value. 
That means that the value is copied from the argument and that copy is local to the function. When the function ends, so does the copied value.

See what happens when we try to change values inside a function

```c
#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    //prints:  In 'swap', a is 4 and b is 3.
    printf("In 'swap', a is %d and b is %d.\n", a, b);
}

int main() {
    int a = 3, b = 4;
    swap(a, b);
    // prints: After 'swap', a is 3 and b is 4
    printf("After 'swap', a is %d and b is %d.\n", a, b);
    return 0;
}
```

This is because, even though the variables have the same names, `a` and `b` in `swap()` are not the same `a` and `b` in `main()`.
They are _copies_ of the values of `a` and `b`.
Can we change `swap` to make it work as we intend?

Yes we can!
We can pass in the addresses of `a` and `b` as pointers.
But, what good will that do, since the function copies the pointers?
It is good, because a copied address is still the same address.
By dereferencing the address we can get access to the original value as it was defined in `main`

```c
#include <stdio.h>

// pass in pointers to a and b
void swap(int *a, int *b) {
    // set temp to value at a's dereferenced address
    int temp = *a;

    // set a's value to value at b's dereferenced address
    *a = *b;

    // set b's value to temp
    *b = temp;

    // prints: In 'swap', a is 4 and b is 3.
    printf("In 'swap', a is %d and b is %d.\n", *a, *b);
}

int main() {
    int a = 3, b = 4;
    swap(&a, &b);
    // prints: After 'swap', a is 4 and b is 3.
    printf("After 'swap', a is %d and b is %d.\n", a, b);
    return 0;
}
```

That's a lot of `*`s in `swap` now, but it now works as intended.

A way to read the dereference operator is "value at".
So, `*a` is the value at `a`.
How well does this work with strings?

## Pointers to Char

We know that the value of an array variable is the address where the array starts.
And we know we can define a string as either a char array, `char my_string[]`, or as a pointer to `char`, `char *`.
How are they different?

In this code we pass a `char *` argument to `describe_me`.
The `adjective` argument is defined as a `char` array and is accepted by the function as a pointer to `char`.

```c
#include <stdio.h>
#include <string.h>

// takes pointer to char
void describe_me(char *adjective){
    strcpy(adjective, "evil");
    // prints: I am evil.
    printf("I am %s.\n", adjective);
}

int main() {
    // defined as a char array
    char adjective[] = "good";
    describe_me(adjective);
    // prints: I am really evil.
    printf("I am really %s.\n", adjective);
    
    return 0;
}
```

We are able to make a persistent change to `adjective`, demonstrating that the defined char array can be accepted as a pointer to char.

Now let's try defining `adjective` as a pointer to `char` directly.

```c
// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

void describe_me(char *adjective){
    // segmentation fault on this line
    strcpy(adjective, "evil");
    printf("I am %s.\n", adjective);
}

int main() {
    char *adjective= "good";
    describe_me(adjective);
    printf("I am really %s.\n", adjective);
    
    return 0;
}
```

Remember how pointers are powerful, but also potentially dangerous?
But why doesn't it work?
An array is a pointer and a pointer worked with a char array!
The reason is that, before, `adjective` was defined as a `char` array which is a variable belonging to `main`.
Now, `adjective` is defined as a string _literal_, meaning that it is written to read-only static memory which belongs to the entire program.
Trying to change a literal string value is like trying to change the literal value of `5`.
It is not allowed.
So, the problem isn't really that it's a pointer.
The problem is what it is pointing to.
