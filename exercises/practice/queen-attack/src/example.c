#include "queen_attack.h"

#define ROW_COUNT 8
#define COLUMN_COUNT 8

attack_status_t can_attack(position_t white_queen, position_t black_queen)
{
   if ((white_queen.column == black_queen.column
        && white_queen.row == black_queen.row) || white_queen.row >= ROW_COUNT
       || white_queen.column >= COLUMN_COUNT || black_queen.row >= ROW_COUNT
       || black_queen.column >= COLUMN_COUNT) {
      return INVALID_POSITION;
   }

   if (white_queen.column == black_queen.column ||
       white_queen.row == black_queen.row ||
       (white_queen.row - black_queen.row ==
        white_queen.column - black_queen.column)
       || (white_queen.row - black_queen.row ==
           black_queen.column - white_queen.column)) {
      return CAN_ATTACK;
   }

   return CAN_NOT_ATTACK;
}
