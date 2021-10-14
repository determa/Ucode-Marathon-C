#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  /* open() and O_XXX flags */
#include <stdbool.h>

void error_list(int argc, char* argv[]);
bool mx_isspace(char c);
int mx_strlen(const char *s);
bool mx_isdigit(int c);
long mx_atoi(const char* str);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
void mx_printint(int n);

