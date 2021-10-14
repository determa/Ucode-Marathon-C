char *mx_strchr();
int mx_strlen();
int mx_strncmp();

char *mx_strstr(const char *s1, const char *s2) {
    int i = mx_strlen(s2);
    const char *str = s1;
    while((str = mx_strchr(str, *s2)) != 0) {
        if (mx_strncmp(str, s2, i) == 0) {
            return (char*)str;
        }
        str++;
    }
    return 0;
}

