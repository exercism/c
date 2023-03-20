# Helper functions

**queen_attack.h**

```c
#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

#endif
```

**queen_attack.c**

```c
static bool is_valid_position(position_t pos)
{
   return pos.row < 8 && pos.column < 8;
}

static bool has_valid_positions(position_t pos_1, position_t pos_2)
{
   if (!is_valid_position(pos_1) || !is_valid_position(pos_2))
      return false;
   return !(pos_1.row == pos_2.row && pos_1.column == pos_2.column);
}

static bool is_on_straight_or_diagonal(position_t pos_1, position_t pos_2)
{
   return pos_1.row == pos_2.row || pos_1.column == pos_2.column ||
          abs(pos_2.row - pos_1.row) == abs(pos_2.column - pos_1.column);
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
   return (!has_valid_positions(queen_1, queen_2))       ? INVALID_POSITION
          : is_on_straight_or_diagonal(queen_1, queen_2) ? CAN_ATTACK
                                                         : CAN_NOT_ATTACK;
}
```

This approach defines several helper functions with the `static` keyword to indicate the functions have [internal linkage][internal-linkage].
Functions in the source file with internal linkage do not have to be declared in the header file as part of the "public interface".
Since code external to the source file does not have access to the `static` functions in the source file, the `static` functions
can be modified or removed without breaking the external code.

The `is_valid_position` function checks that a position is valid, i.e., not beyond the chessboard.

The `has_valid_positions` function uses `is_valid_position` to check that the position for each queen is valid,
and then checks that the queen positions are valid in relation to each other, i.e., not occupying the same square.

The `is_on_straight_or_diagonal` function checks if the queens are on the same rank or file, or if they are diagonal to each other.

The [`abs`][abs] function in [stdlib.h][stdlib] is used to calculate the diagonal.

- For example, if queen 1 is on position `2,2`, and queen 2 is on position `4,4`, then `4 - 2 = 2` (the absolute of which is `2`) 
equals `4 - 2 = 2` (the absolute of which is `2`.)

- If queen 1 is on position `4,4`, and queen 2 is on position `2,2`, then `2 - 4 = -2` (the absolute of which is `2`)
equals `2 - 4 = -2` (the absolute of which is `2`.)

- If queen 1 is on position `4,4`, and queen 2 is on position `2,1`, then `2 - 4 = -2` (the absolute of which is `2`)
does not equal `1 - 4 = -3` (the absolute of which is `3`.)

The `can_attack` function uses a couple of chained [ternary operators][ternary] that use the helper functions to return the answer.

```exercism/note
Some coders do not find chained ternary operators to be as readable as a series of `if`, `else/if`, and/or `else` statements,
which could be used here instead.
```

If the first ternary expression determines the positions are not valid, then `INVALID_POSITION` is returned.
Otherwise, the second ternary expression checks if the queens can attack each other.
If so, then `CAN_ATTACK` is returned.
Otherwise, `CAN_NOT_ATTACK` is returned.

[internal-linkage]: https://www.geeksforgeeks.org/internal-linkage-external-linkage-c/
[abs]: https://www.tutorialspoint.com/c_standard_library/c_function_abs.htm
[stdlib]: https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm
[ternary]: https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/
