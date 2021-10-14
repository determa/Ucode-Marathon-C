#include <unistd.h>

void mx_printchar(char c) {
    char* ch = &c;
    write(1, ch, 1);
}
