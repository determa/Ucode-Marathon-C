#include <stdbool.h>

char *mx_strtrim();
bool mx_isspace();
char *mx_strnew();
int mx_strlen();
void mx_strdel();

char *mx_del_extra_whitespaces(const char *str) {
    if (str == 0) {
        return 0;
    }
    char *c = mx_strtrim(str);
    int chet = 0;
    int space = 0;
    int words = 0;
    int size = mx_strlen(c);
    int i = 0;

    while (c[i] != 0) {
        if (!mx_isspace(c[i])) {
            chet = 0;
            words++;
        }
        if (chet == 0 && mx_isspace(c[i])) {
            chet = 1;
            space++;
        }
        i++;
    }
    char *new = mx_strnew(words + space);
    int j = 0;
    chet = 0;
    for (int i = 0; i < size; i++) {
        if (!mx_isspace(c[i])) {
            new[j++] = c[i];
            chet = 0;
        }
        if (chet == 0 && mx_isspace(c[i])) {
            new[j++] = ' ';
            chet = 1;
        }
    }
    mx_strdel(&c);
    return new;
}

