#include <stdbool.h>

bool mx_isdigit(int c) {
    if (c >= 48 && c <= 57) {
        return true;
    }
    else {
        return false;
    }
}

int mx_atoi(const char *str) {
    int i = 0;
    long int res = 0;
    int negative = 1;
    if (str[i] == '-') {
        negative = -1;
        i++;
    }
    if (str[i] == '+') {
        i++;
    }
    while (mx_isdigit(str[i])) {
        res = res * 10;
        res = res + (str[i] - 48);
        i++;
    }
    return (negative * res);
}

