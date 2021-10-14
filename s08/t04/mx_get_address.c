#include "get_address.h"

char *mx_get_address(void *p) {
    unsigned long pointer = (unsigned long) &p;
    const char * address = mx_nbr_to_hex(pointer);
    int lenght = mx_strlen(address);
    char *result = malloc(lenght + 2);
    *result++ = '0';
    *result++ = 'x';
    result = mx_strcpy(result, address);
    return result -= 2;
}

