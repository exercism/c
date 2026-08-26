#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

#include <stdint.h>

typedef enum {
} resistor_band_t;

uint16_t color_code(resistor_band_t color);

const resistor_band_t *colors(void);

#endif
