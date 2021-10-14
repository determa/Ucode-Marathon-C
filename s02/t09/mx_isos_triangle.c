#include <unistd.h>
void mx_printchar();

void mx_isos_triangle(unsigned int length, char c) {
    for(unsigned int i = 1; i <= length; i++) {
        for(unsigned int j = 0; j < i; j++)
            mx_printchar(c);
        write(1, "\n", 1);
    }
}
