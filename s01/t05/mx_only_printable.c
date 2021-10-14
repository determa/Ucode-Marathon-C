#include <unistd.h>
void mx_printchar();

void mx_only_printable(void) {
    for (int i=127; i >= 0; i--)
        mx_printchar(i);
    write(1, "\n", 1);
}
