#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_strlen(const char *s);
long long mx_atoi(const char *str);
double mx_pow(double n, unsigned int pow);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str); 
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_itoa(long long number);

void mx_error_invalid_operand(char *operand);
void mx_error_invalid_operation(char* operation);
void mx_error_invalid_result(char* result);

void mx_print_equation(char *op1, char *operation, char *op2, char *res, 
                       int op1_len, int op2_len, int res_len);
                       
void mx_print_res(int i, char *operation, int j, int k);

#endif

