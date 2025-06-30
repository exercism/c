#ifndef FLOWER_FIELD_H
#define FLOWER_FIELD_H
#include <stddef.h>

char **annotate(const char **garden, const size_t rows);
void free_annotation(char **annotation);

#endif
