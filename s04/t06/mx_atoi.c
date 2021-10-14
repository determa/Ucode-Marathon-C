#include <stdbool.h>

bool mx_isspace();
bool mx_isdigit();

int mx_atoi(const char *str) {
    int n = 0, negative = 1;
    if (*str == '-') {
        negative = -1;
        str++;
    }
    while(*str != '\0') {
        if (mx_isspace(*str) || *str == '-' || *str == '.') {
            break;
        }
        if (mx_isdigit(*str)) {
            n *= 10;
            n += *str++;
            n -= '0';
        }
    }
    return (negative * n);
}

