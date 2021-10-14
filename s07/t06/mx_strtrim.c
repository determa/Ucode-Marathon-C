#include <stdbool.h>

bool mx_isspace();
int mx_strlen();
char *mx_strnew();
char *mx_strncpy();
void mx_strdel();

char *mx_strtrim(const char *str) {
    if (str == 0) {
        return 0;
    }
    int size = mx_strlen(str);
    int start = 0;
    int end = 0;
    char *src = mx_strnew(size);
    src = mx_strncpy(src, str, size);

    for(; start < size; start++) {
        if (!mx_isspace(str[start])) {
            break;
        }
    }
    for(int i = size - 1; i > 0; i--) {
        if (!mx_isspace(str[i])) {
            break;
        }
        end++;
    }
    char *new = mx_strnew(size - start - end);
    int j = 0;
    for (int i = start; i < size - end; i++) {
        new[j++] = src[i];
    }
    mx_strdel(&src);
    return new;
}

