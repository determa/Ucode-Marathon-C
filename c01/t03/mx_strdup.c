#include <stdlib.h>

char *mx_strcpy(char *dst, const char *src) {
    unsigned i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        ++i;
    }
    dst[i] = '\0';
    return dst;
}

int mx_strlen(const char *s) {
    int length = 0;
    while(*s != '\0') {
        s++;
        length++;
    }
    return length;
}

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

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *c = mx_strnew(size);
    mx_strcpy(c, str);
    return c;
}

