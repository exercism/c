#ifndef SUBLIST_H
#define SUBLIST_H

#include <stddef.h>

enum {
   EQUAL,
   UNEQUAL,
   SUBLIST,
   SUPERLIST
};

int check_lists(int *listOne, int *listTwo, size_t listOneLength,
                size_t listTwoLength);

#endif
