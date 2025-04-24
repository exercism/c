# Introduction

There are several ways to solve Queen Attack.
All of the code to validate the input and calculate the answer could be placed in the `can_attack` function.
Another approach could break the logic up into some helper functions.

## Approach: Helper functions

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

For more information, check the [Helper functions approach](approach-helper-functions).

[approach-helper-functions]: https://exercism.org/tracks/c/exercises/queen-attack/approaches/helper-functions
