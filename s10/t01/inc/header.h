#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>	/* open() and O_XXX flags */
#include <sys/stat.h>	/* S_IXXX flags */
#include <sys/types.h>	/* mode_t */
#include <errno.h>
#include <string.h>

int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printstr(const char *s);

#endif

