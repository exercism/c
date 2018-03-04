#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

char **annotate(const char **minefield, const size_t rows);

#endif
