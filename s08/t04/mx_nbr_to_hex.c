#include "get_address.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *numb = NULL;
    unsigned long num = nbr;
    int l = 0;

    while (nbr) {
        nbr /= 16;
        l++;
    }

    int temp;

    numb = mx_strnew(l);

    while (num) {
        temp = num % 16;
        if (temp < 10)
            numb[--l] = 48 + temp;
        if (temp >= 10)
            numb[--l] = 87 + temp;
        num /= 16;
    }
    return numb;
}

