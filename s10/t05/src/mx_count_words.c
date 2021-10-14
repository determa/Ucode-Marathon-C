#include "../inc/header.h"

int mx_count_words(const char *str, char delimiter) {
    int count = 0;
    int i = 0;
    for (; str[i] != '\0'; i++) {  
        if (str[i] == delimiter && str[i + 1] != delimiter) {
            count++;
        }
    }
    if (str[0] != delimiter) {
        count++;
    }
    if (str[i - 1] == delimiter) {
        count--;
    }
    return count;
}

