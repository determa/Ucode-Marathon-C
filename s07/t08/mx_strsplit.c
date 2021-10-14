#include <stdlib.h>

int mx_count_words();
char *mx_strnew();
char *mx_strncpy();


char **mx_strsplit(char const *s, char c) {
    if (s == 0) {
        return 0;
    }
    int count = mx_count_words(s, c);
    int j = 0;
    char **arr = (char**)malloc(count);
    for (int i = 0; i < count; i++) {
        int word_length = 0;
        int start = 0;
        for (; s[j]; j++) {
            if (s[j] != c) {
                word_length++;
                if (start == 0) {
                    start = j;
                }
            }
            else {
                if (s[j] == c && word_length) {
                    break;
                }
            }
        }
        char *word = mx_strnew(word_length);
        for (int z = 0, m = start; m < j; z++, m++) {
            word[z] = s[m];
        }
        arr[i] = word;
    }
    arr[count] = 0;
    return arr;
}

