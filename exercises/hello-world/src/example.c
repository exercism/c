#include <stdio.h>
#include "hello_world.h"

void hello(char* buffer, unsigned int buffer_length, const char* name) {
    if (name == NULL) name = "World";

    snprintf(buffer, buffer_length, "Hello, %s!", name);
}
