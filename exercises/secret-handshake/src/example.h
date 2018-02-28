#ifndef SECRET_HANDSHAKE_H
#define SECRET_HANDSHAKE_H
#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

const char **commands(size_t number);

#endif
