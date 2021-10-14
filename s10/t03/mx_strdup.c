#include "file_to_str.h"

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *c = mx_strnew(size);
    mx_strcpy(c, str);
    return c;
}

