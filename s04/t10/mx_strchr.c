char *mx_strchr(const char *s, int c) {
    while (*s) {
        if (*s == c) {
            return (char*)s;
        }
        if(!*s++) {
            return 0;
        }
    }
    return 0;
}

