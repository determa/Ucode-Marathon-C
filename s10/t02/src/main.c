#include "../inc/header.h"


int main(int argc, char *argv[]) {
    char sym = 0;
    if (argc == 1) {
        while (read(0, &sym, 1)) {
            write(1, &sym, 1);
        }
    }
    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0) {
            mx_printerr("mx_cat: ");
            mx_printerr(argv[i]);
            mx_printerr(": No such file or directory\n");
        }
        else {
            while(read(fd, &sym, 1)) {
                write(1, &sym, 1);
            }
        }
        close(fd);
    }
    exit(0);
}

