#include <stdio.h>

void hello(char* buffer, unsigned int buffer_length, const char* name){
    
    if (name[0] == '\0') name = "World";
    
    snprintf(buffer, buffer_length, "Hello, %s!", name);
}