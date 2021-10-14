#include "../inc/header.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        exit(-1);
    }

    ssize_t read_b;
    ssize_t write_b;
    char res;
    int fd1 = open (argv[1], O_RDONLY);
    errno = 0;
        
    if (fd1 < 0) {
        errno = 2;
        mx_printerr(strerror(errno));
        mx_printchar('\n');
        exit(-1);
	}

    // read and write, rw- --- ---
    int fd2 = open (argv[2], O_RDWR | O_CREAT | S_IWUSR);
    
    while ((read_b = read (fd1, &res, 1)) > 0)   {		
		write_b = write (fd2, &res, read_b);
	}

    if (read_b < 0 || write_b < 0) {
		mx_printerr("error");
        mx_printchar('\n');
		exit(-1);
	}
    
	if (close (fd1) != 0 || close (fd2) != 0) {
        mx_printerr("error");
        mx_printchar('\n');
        exit(-1);
	}

    close (fd1);
    close (fd2);
    exit(0);
}

