#include "../inc/header.h"


int main(int argc, char *argv[]) {
    char buf = 0;
    char last_word = 0;
    int words = 0;
    int lines = 0;
    int bytes = 0;

    if (argc == 1) {
        while (read(0, &buf, 1)) {
            if(mx_isspace(buf) && !mx_isspace(last_word))
                words++;
            if(buf == '\n')
                lines++;
            bytes++;
            last_word = buf;
        }
        mx_printstr("\t");
        mx_printint(lines);
        mx_printstr("\t");
        mx_printint(words);
        mx_printstr("\t");
        mx_printint(bytes);
    }

    for (int i = 1; i < argc; i++) {
        last_word = 0;
        int tmp_words = 0;
        int tmp_lines = 0;
        int tmp_bytes = 0;

        int fd = open(argv[i], O_RDONLY);

        if (fd < 0) {
            mx_printerr("mx_cat: ");
            mx_printerr(argv[i]);
            mx_printerr(": No such file or directory\n");
        }
        else {
            while (read(fd, &buf, 1)) {
                if(mx_isspace(buf) && !mx_isspace(last_word))
                    tmp_words++;
                if(buf == '\n')
                    tmp_lines++;
                tmp_bytes++;
                last_word = buf;
            }
        }

        words += tmp_words;
        lines += tmp_lines;
        bytes += tmp_bytes;

        mx_printstr("\t");
        mx_printint(tmp_lines);
        mx_printstr("\t");
        mx_printint(tmp_words);
        mx_printstr("\t");
        mx_printint(tmp_bytes);
        mx_printchar(' ');
        mx_printstr(argv[i]);
        mx_printchar('\n');
        close(fd);
    }
    if (argc >= 3) {
        mx_printstr("\t");
        mx_printint(lines);
        mx_printstr("\t");
        mx_printint(words);
        mx_printstr("\t");
        mx_printint(bytes);
        mx_printchar(' ');
        mx_printstr("total");
        mx_printchar('\n');
    }
    exit(0);
}

