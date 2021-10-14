#include <unistd.h>

int mx_strlen(const char *s) {
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}

void mx_printchar(char c) {
    write (1, &c, 1);
}

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}

void mx_printint(int n) {
    int num = n;
    if(num < 0) {
        mx_printchar('-');
        num = num * -1;
    }
    if(num > 10)
        mx_printint(num / 10);
    mx_printchar((num % 10) + 48);
}

int main(int argc, char **argv) {
    mx_printstr(*argv);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
    return 0;
}

