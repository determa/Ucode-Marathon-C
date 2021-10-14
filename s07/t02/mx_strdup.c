char *mx_strcpy();
int mx_strlen();
char *mx_strnew();

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *c = mx_strnew(size);
    mx_strcpy(c, str);
    return c;
}

