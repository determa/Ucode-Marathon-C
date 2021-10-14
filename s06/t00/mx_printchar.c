#include <unistd.h>

void mx_printchar(char c) {
    char* character = &c;
    write(1, character, 1);
}

