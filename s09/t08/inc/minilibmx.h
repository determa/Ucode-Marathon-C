#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
void mx_printerr(const char *s);

#endif

