#include "gigasecond.h"

#define GIGASECOND 1000000000

void gigasecond(time_t start, char *buffer, size_t size) {
    time_t after = start + GIGASECOND;
    struct tm *t = gmtime(&after);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

