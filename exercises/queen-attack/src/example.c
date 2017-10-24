#include "queen_attack.h"

#define ROW_COUNT 8
#define COLUMN_COUNT 8

uint8_t can_attack(queen_position_t queen_1, queen_position_t queen_2)
{
    if ((queen_1.column == queen_2.column && queen_1.row == queen_2.row) ||
        queen_1.row >= ROW_COUNT ||
        queen_1.column >= COLUMN_COUNT ||
        queen_2.row >= ROW_COUNT ||
        queen_2.column >= COLUMN_COUNT) {
        return INVALID_POSITION;
    }

    if (queen_1.column == queen_2.column ||
        queen_1.row == queen_2.row ||
        (queen_1.row - queen_2.row == queen_1.column - queen_2.column) ||
        (queen_1.row - queen_2.row == queen_2.column - queen_1.column)) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
