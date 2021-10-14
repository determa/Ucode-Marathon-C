#include <time.h>

double mx_timer(void(*f)()) {
    clock_t start = clock(), end;
    (*f)();
    end = clock();
    double ftime = (double)(end - start) / CLOCKS_PER_SEC;
    if (start <= 0 || end <= 0 || end < start)
        return -1;
    return ftime;
}

