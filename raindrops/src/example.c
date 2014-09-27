#include "raindrops.h"
#include "stdio.h"
#include "string.h"

#define PLING_FACTOR 3
#define PLANG_FACTOR 5
#define PLONG_FACTOR 7

char* convert(char *buffer, int buffer_length, int drops)
{
    memset(buffer, '\0', sizeof(char)*buffer_length);
    if ( (drops % PLING_FACTOR != 0) &&
         (drops % PLANG_FACTOR != 0) &&
         (drops % PLONG_FACTOR != 0) )
    {
        snprintf (buffer, buffer_length, "%d", drops);
    }
    else
    {
        snprintf
        (
            buffer,
            buffer_length,
            "%s%s%s",
            drops % PLING_FACTOR == 0 ? "Pling" : "",
            drops % PLANG_FACTOR == 0 ? "Plang" : "",
            drops % PLONG_FACTOR == 0 ? "Plong" : ""
        );
    }
    return buffer;
}

