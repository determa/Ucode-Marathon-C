#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct  s_agent {
    char *name;
    int power;
    int strength;
}               t_agent;

int mx_strlen(const char *s);
void mx_printerr(const char*s);
void mx_strdel(char **str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strnew(const int size);
int mx_strcmp (const char *s1, const char *s2);
char* mx_strncpy(char *dst, const char *src, int len);
int mx_count_words(const char *str, char delimiter);
char **mx_strsplit(char const *s, char c);
int mx_atoi(const char* str);
void mx_print_agents(t_agent **agents, int count_of_agents);

#endif
