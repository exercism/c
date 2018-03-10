#include "two_fer.h"
#include <stdio.h>

#define BUFFER_SIZE (100)
#define SEQUENCE "One for %s, one for me."

void two_fer(char *buffer, const char *name)
{
   snprintf(buffer, BUFFER_SIZE, SEQUENCE,
            (buffer == NULL || name == NULL) ? "you" : name);
}
