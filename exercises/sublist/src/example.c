#include "sublist.h"
#include <stdbool.h>
#include <string.h>

static bool is_equal(int *listOne, int *listTwo, size_t listOneLength, size_t listTwoLength)
{
    return (listOneLength == listTwoLength && !memcmp(listOne, listTwo, listOneLength));
}

static bool is_sublist(int *listOne, int *listTwo, size_t listOneLength, size_t listTwoLength)
{
    int i;
    int loop_end = listTwoLength > listOneLength ? listTwoLength - listOneLength : 0;

    if (listOneLength == 0) {
        return true;
    }

    for (i = 0; i < loop_end; i++) {
        if (!memcmp(listOne, &listTwo[i], listOneLength)) {
            return true;
        }
    }

    return false;
}

static bool is_superlist(int *listOne, int *listTwo, size_t listOneLength, size_t listTwoLength)
{
    (void)listOne;
    (void)listTwo;
    (void)listOneLength;

    if (listTwoLength == 0) {
        return true;
    }

    return false;
}

int check_lists(int *listOne, int *listTwo, size_t listOneLength, size_t listTwoLength)
{
    if (is_equal(listOne, listTwo, listOneLength, listTwoLength)) {
        return EQUAL;
    } else if (is_sublist(listOne, listTwo, listOneLength, listTwoLength)) {
        return SUBLIST;
    } else if (is_superlist(listOne, listTwo, listOneLength, listTwoLength)) {
        return SUPERLIST;
    }

    return UNEQUAL;
}
