#include "duplicate.h"
#include <stdlib.h>

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (src == NULL) {
        return NULL;
    }
    for (int i = 0; i < src->size; i++) {
        for (int j = i + 1; j < src->size; j++) {
            if (src->arr[i] == src->arr[j] ) {
                for (int a = j; a < src->size - 1; a++) {
                    src->arr[a] = src->arr[a + 1];
                }
                src->size -= 1;
                if (src->arr[i] == src->arr[j]) {
                    j--;
                }
            }
        }
    }
    t_intarr *dst = malloc(16);
    if (dst) {
        dst->size = src->size;
        dst->arr = mx_copy_int_arr(src->arr, dst->size);
        return dst;
    }
    return NULL;
}

