#include <stdbool.h>
bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(char *str) {
    int res = 0;
    int negative = 1;
    int i = 0;
    if (str[i] == '-') {
        negative = -1;
        i++;
    }
    if (str[i] == '+') {
        i++;
    }
    while (str[i]) {
        if (!mx_isdigit(str[i]))
            return 0;
        res = res * 10;
        res = res + (str[i] - 48);
        i++;
    }
    return (negative * res);
}

