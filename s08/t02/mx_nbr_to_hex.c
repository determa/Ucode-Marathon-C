#include "nbr_to_hex.h"

char *mx_nbr_to_hex(unsigned long nbr) {
   
    int nbr2 = nbr;
    int l = 0;
    int tmp;

    while (nbr != 0) {
        nbr /= 16;
        l++;
    }
    if (l == 0)
        return 0;
        
    char *string = mx_strnew(l);
    for (int i = l - 1; i >= 0; i--) {
        tmp = nbr2 % 16;

        if (tmp < 10)
            string[i] = tmp + 48;
        else
            string[i] = tmp + 32 + 55;

        nbr2 /= 16;
    }
    return string;
}

