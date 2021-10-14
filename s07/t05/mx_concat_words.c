int mx_strlen();
char *mx_strjoin();
void mx_strdel();

char *mx_concat_words(char **words) {
    if (words == 0) {
        return 0;
    }
    char *string = 0;
    while (*words != 0) {
        string = mx_strjoin(string, *words++);
        if(*words != 0) {
            string = mx_strjoin(string, " ");
        }
    }
    mx_strdel(words);
    return string;
}

