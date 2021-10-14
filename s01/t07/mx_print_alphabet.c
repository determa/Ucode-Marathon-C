#include <unistd.h>
void mx_printchar();

void mx_print_alphabet(void) {
    int a = 65, b = 97, change = 0;
    for(int i=0; i<=25; i++) {
        if (!change)
            mx_printchar(a+i);
        else
            mx_printchar(b+i);
        change = !change;
    }
    write(1, "\n", 1);
}
