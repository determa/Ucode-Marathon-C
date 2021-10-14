#include <unistd.h>

void mx_printint(int n) {
    int num = n;
    if(num < 0) {
        write (1, "-", 1);
        num = num * -1;
    }
    if(num >= 10)
        mx_printint(num / 10);
    char m = (num % 10) + 48;
    write (1, &m, 1);
}

