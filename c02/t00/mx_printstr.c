#include <unistd.h>

int mx_strlen(const char *s) {
	return (*s) ? mx_strlen(++s) + 1 : 0;
}

void mx_printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

