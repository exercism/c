#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>

enum result {
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION
};

typedef struct {
    uint8_t row;
    uint8_t column;
} queen_position_t;

uint8_t can_attack(queen_position_t queen_1, queen_position_t queen_2);

#endif
