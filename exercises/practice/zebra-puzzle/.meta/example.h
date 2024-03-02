#ifndef ZEBRA_PUZZLE_H
#define ZEBRA_PUZZLE_H

typedef struct {
   const char *drinks_water;
   const char *owns_zebra;
} solution_t;

solution_t solve_puzzle(void);

#endif
