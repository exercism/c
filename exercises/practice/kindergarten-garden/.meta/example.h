#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H

typedef enum { CLOVER = 0, GRASS = 1, RADISHES = 2, VIOLETS = 3 } plant_t;

void plants(const char *diagram, const char *student, plant_t *plants);

#endif
