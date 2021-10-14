#include "../inc/part_of_the_matrix.h"

int mx_strlen(const char *s) {
    int k = 0;
    while(*s != '\0') {
        s++;
        k++;
    }
    return k;
}

