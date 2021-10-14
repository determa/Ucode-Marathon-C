int mx_strlen(const char *s) {
    int k = 0;
    while(*s != '\0') {
        s++;
        k++;
    }
    return k;
}

