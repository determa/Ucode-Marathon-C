#include <unistd.h>
void mx_printstr();

void mx_is_positive(int i) {
    if (i < 0)
        mx_printstr("negative");
    else if (i == 0)
        mx_printstr("zero");
    else
        mx_printstr("positive");
}
