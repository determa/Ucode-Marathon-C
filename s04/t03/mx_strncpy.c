char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}

