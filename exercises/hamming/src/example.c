#include <stddef.h>
#include <string.h>
#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    size_t lhs_len = strlen(lhs);
    size_t rhs_len = strlen(rhs);
    int count = 0;
    int i = 0;
    for (i = 0; i < lhs_len && i < rhs_len; ++i) {
        if(lhs[i] != rhs[i]) {
            ++count;
        }
    }
    return count;
}
