#ifndef ZEBRA_PUZZLE_H
#define ZEBRA_PUZZLE_H

struct solution
{
   const char *drinks_water;
   const char *owns_zebra;
};

struct solution solve_puzzle(void);

#endif
