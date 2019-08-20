#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
   size_t row, column;
} saddle_point_t;

typedef struct {
   size_t count;
   saddle_point_t points[];
} saddle_points_t;

saddle_points_t *saddlePoints(size_t rows, size_t columns,
                              uint8_t matrix[][columns]);

#endif
