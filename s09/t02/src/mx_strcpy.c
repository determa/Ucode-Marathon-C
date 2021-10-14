char *mx_strcpy(char *dst, const char *src) {
    char *tm = dst;
    while (*src) {
        *dst++ = *src++;
    }
    return tm;
}

