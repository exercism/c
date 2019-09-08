#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

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
   GREY = 8,
   WHITE = 9
} resistor_band_t;

typedef enum {
   OHMS = 0,
   KILOOHMS = 1,
   MEGAOHMS = 2,
   GIGAOHMS = 3,
   TERAOHMS = 4,
   PETAOHMS = 5,
   EXAOHMS = 6,
} resistor_unit_t;

typedef struct {
   uint16_t value;
   resistor_unit_t unit;
} resistor_value_t;

resistor_value_t colorCode(resistor_band_t colors[]);

#endif
