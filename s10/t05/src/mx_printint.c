#include "../inc/header.h"

void mx_printint(int n) {
    int length = 0;
    int n2 = n;
    int mines = 0;
    if (n < 0) {
        n = -n;
        length = 1;
        mines = 1;
    }
    while (n2 != 0) {
        n2 /= 10;
        length++;
    }
    char str[length]; 
    if (n == 0) {
        length = 1;
    }
    if (mines == 1) {
        length--;
    }
    for (int i = 0; i < length; i++) {
        str[i] = n % 10 + 48;
        n /= 10;
    }
    if (mines == 1) {
        length++;
        str[length - 1] = '-';
    }
    for (int j = length - 1; j >= 0; j--) {
        mx_printchar(str[j]);    
    }
}

