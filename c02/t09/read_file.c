#include <unistd.h>
#include <fcntl.h>

int mx_strlen(const char *s) {
    int i = 0;
	for (; s[i] != '\0'; i++) {}
	return i;
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

int main(int argc, char *argv[]) {
    char sym = 0;
    if (argc != 2) {
        mx_printerr("usage: ./read_file [file_path]\n");
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("error\n");
        return -1;
    }
    int rd;
    while((rd = read(fd, &sym, 1)) > 0) {
        write(1, &sym, 1);
        if (rd < 0) {
            mx_printerr("error\n");
            return -1;
        }
    }
    close(fd);
    return 0;
}

