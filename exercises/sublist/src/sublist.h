#ifndef SUBLIST_H
#define SUBLIST_H

#include <stddef.h>

typedef enum {
   EQUAL,
   UNEQUAL,
   SUBLIST,
   SUPERLIST
} comparison_result_t;

comparison_result_t check_lists(int *listOne, int *listTwo,
                                size_t listOneLength, size_t listTwoLength);

#endif
