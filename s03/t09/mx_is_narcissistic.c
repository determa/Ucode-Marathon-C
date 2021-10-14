#include <stdbool.h>
double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num){

    int i = 0;
    int num2 = num;
    for (i = 0; num2 > 0; i++) {
        num2 /= 10;
    }
    int res = 0;

    for (int j = num; j != 0; j /= 10) {
        res += mx_pow(j % 10, i);
    }
    if (res == num) {
        return true;
    }
    else {
        return false;
    }
}

