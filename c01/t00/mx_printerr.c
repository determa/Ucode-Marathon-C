#include <unistd.h>

int mx_strlen(const char *s) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

