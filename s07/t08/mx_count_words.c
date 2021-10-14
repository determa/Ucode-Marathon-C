int mx_count_words(const char *str, char delimiter) {
    int word = 0, i = 0;
    if (str[0] != delimiter && str[0] != '\0') {
        word++;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] == delimiter) {
            while (str[i] != '\0' && str[i] == delimiter) {
                i++;
            }
            if(str[i] != delimiter && str[i] != '\0') {
                word++;
            }
        }
        i++;
    }
    return word;
}

