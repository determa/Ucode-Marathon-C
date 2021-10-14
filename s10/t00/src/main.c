#include "../inc/header.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./read_file [file_path]\n");
        return -1;
    }

    ssize_t ret;
    char res;
    int fd = open (argv[1], O_RDONLY, S_IRUSR);

    if (fd < 0) {
		mx_printerr("error");
        mx_printchar('\n');
        return -1;
	}
    
    while ((ret = read(fd, &res, 1)) > 0) {
		mx_printchar(res);
	}

    if (ret < 0) {
		mx_printerr("error");
        mx_printchar('\n');
		return -1;
	}
    
	if (close (fd) != 0) {
		mx_printerr("error");
        mx_printchar('\n');
        return -1;
	}

    mx_printchar('\n');
    close (fd);
    return 0;
}

