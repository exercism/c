#ifndef SAY_H
#define SAY_H
#include <stdint.h>
#include <stddef.h>

typedef struct {
   const char *name;
   size_t size;
} map;

int say(int64_t input, char **ans);

#endif
