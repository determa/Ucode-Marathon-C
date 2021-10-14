#ifndef MATRIX_H
#define MATRIX_H

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct s_display {
	int len;
	int start;
	int finish;
	wchar_t *arr;
} t_display;

int mx_strcmp(const char *, const char *);
void mx_matrix(WINDOW *, int, char **);
void mx_print_text(WINDOW *, int, int);
wchar_t mx_japanese();

#endif

