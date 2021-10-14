#include "../inc/header.h"

bool mx_isspace(char c) {
    if (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f' || c == '\n') {
        return true;
    }
    else {
        return false;
    }
}

