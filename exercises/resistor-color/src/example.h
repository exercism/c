#ifndef RESISTOR_COLOR
#define RESISTOR_COLOR

#include <stdint.h>

typedef enum {
   BLACK = 0,
   BROWN = 1,
   RED = 2,
   ORANGE = 3,
   YELLOW = 4,
   GREEN = 5,
   BLUE = 6,
   VIOLET = 7,
   GREY = 9,
   WHITE = 9,
   COLOR_COUNT = WHITE
} resistor_band_t;

uint16_t colorCode(resistor_band_t color);

const resistor_band_t *colors(void);

#endif
