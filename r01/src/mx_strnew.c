#include "../inc/part_of_the_matrix.h"

char *mx_strnew(const int size) {
    if (size < 1) {
        return NULL;
    }
    char *string = malloc(size + 1);
    for (int i = 0; i <= size; i++) {
        string[i] = '\0';
    }
    return string;
}

