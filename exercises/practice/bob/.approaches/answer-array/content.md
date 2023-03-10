# Answer array

**bob.h**

```c
#ifndef BOB_H
#define BOB_H

char const *hey_bob(char const *greeting);

#endif
```

**bob.c**

```c
#include "bob.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

static char const *const answers[] = { "Whatever.", "Sure.", "Whoa, chill out!",
                                 "Calm down, I know what I'm doing!" };

char const *hey_bob(char const *greeting)
{
   if (!greeting || *greeting == '\0')
      return "Fine. Be that way!";
   char const *end_pos = greeting + strlen(greeting) - 1;
   while (end_pos > greeting && isspace(*end_pos))
      end_pos--;
   if (isspace(*end_pos))
      return "Fine. Be that way!";
   char const *msg = greeting;
   bool shout = true, has_letter = false;
   while (msg <= end_pos) {
      if (isalpha(*msg)) {
         has_letter = true;
         if (!isupper(*msg)) {
            shout = false;
            break;
         }
      }
      msg++;
   }
   int is_shout = shout && has_letter ? 2 : 0;
   int is_question = *end_pos == '?' ? 1 : 0;
   return answers[is_question + is_shout];
}
```

In this approach you define an array that contains Bob’s answers, and each condition is given a score.
The correct answer is selected from the array by using the score as the array index.

The `hey_bob` function starts be testing if pointer to the input string is `NULL`.
If so, the `OR` (`||`) statement [short-circuits][short-circuit] and returns the response for saying nothing.
If the pointer is not `NULL`, then the right side of the `OR` statement tests if the pointer is pointing at the terminating `'\0'`
character.
If so, then it is an empty string, and the response for saying nothing is returned.

The next thing is to calculate where the string ends, disregarding any trailing whitespace.
The `strlen` function from [string.h][string-h] library is used to find the last position of the input string.

The `isspace` function from the [ctype.h][ctype-h] libray is used to check if the character at the `end_pos` is whitespace.
If so, the `end_pos` is decremented.

If all of the characters in the input string are spaces, `end_pos` will be decremented until it is at the first character.
If the first character is also whitespace, then the response for saying nothing is returned.

The next thing is to calculate is the input string is a shout.
The `msg` pointer is initialized to the position of the first character.
The `shout` variable is initialized to `true` as a condition to disprove, and the `has_letter` variable is initialized to `false`
as a condition to prove.
`has_letters  ` is needed, because if the input were only `"123"`, `shout` would never be disproved, but without letters it would not really be a shout.

Each character from the first through the `end_pos` is checked.
The `isalpha` function from `ctype.h` is used to see if `has_letter` should be set to `true`.
If the characters is a letter, it's checked by the `isupper` function from `ctype.h` to see if `shout` should be set to `false`.
If a character is a letter but is not uppercase, then the input string cannot be shout, so `break` is used to exit the loop.

After the loop, a [ternary operator][ternary] is used to set the value for `is_shout` to `2` if both `shout` and `has_letter` are true.
Otherwise `is_shout` is set to `0`.

A ternary operator is used to set the value for `is_question` to `1` if the character at `end_pos` is `'?'`.
Otherwise, `is_question` is set to `0`.

The value of `is_shout` plus `is_question` is used to index into the answers array for returning the correct answer.
For example, giving `is_question` a score of `1` and `is_shout` a score of `0` would use an index of `1` to get the element from the answers array, which is `"Sure."`.

| is_shout | is_question | Index     | Answer                                |
| -------- | ----------- | --------- | ------------------------------------- |
|        0 |           0 | 0 + 0 = 0 | `"Whatever."`                         |
|        0 |           1 | 0 + 1 = 1 | `"Sure."`                             |
|        2 |           0 | 2 + 0 = 2 | `"Whoa, chill out!"`                  |
|        2 |           1 | 2 + 1 = 3 | `"Calm down, I know what I'm doing!"` |

[short-circuit]: https://www.geeksforgeeks.org/short-circuit-evaluation-in-programming/
[string-h]: https://www.tutorialspoint.com/c_standard_library/string_h.htm
[ctype-h]: https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
