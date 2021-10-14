#include <stdbool.h>

bool mx_isspace();
bool mx_isdigit();

int mx_atoi(const char *str) {
    int i = 0;
    int res = 0;
    int negative = 1;
    while (str[i]) {
        if (mx_isspace(str[i])) {
            i++;
        }
        else {
            break;
        }
    }
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

