#include <unistd.h>

void mx_printint();

void mx_print_arr_int(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        mx_printint(arr[i]);
        write (1, "\n", 1);
    }
}

