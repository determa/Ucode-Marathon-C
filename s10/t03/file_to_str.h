#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  /* open() and O_XXX flags */
#include <sys/stat.h>  /* S_IXXX flags */
#include <sys/types.h>  /* mode_t */
#include <errno.h>
#include <string.h>

int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);

#endif

