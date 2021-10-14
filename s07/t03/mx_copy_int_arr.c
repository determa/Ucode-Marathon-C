#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    if (!src) {
        return NULL;
    }
    int *new = malloc(size);
    int i;
    for (i = 0; i < size; i++) {
        new[i] = src[i];
    }
    return new;
}

