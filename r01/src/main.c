#include "../inc/part_of_the_matrix.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [op1] [operation] [op2] [result]\n");
        exit(-1);
    }

    char *op1 = mx_strtrim(argv[1]);
    char *operation = mx_strtrim(argv[2]);
    char *op2 = mx_strtrim(argv[3]);
    char *res = mx_strtrim(argv[4]);
    int op1_len = mx_strlen(op1);
    int operation_len = mx_strlen(operation);
    int op2_len = mx_strlen(op2);
    int res_len = mx_strlen(res);

    if (op1_len <= 0)
        mx_error_invalid_operand(argv[1]);
    if (operation_len != 1)
        mx_error_invalid_operation(argv[2]);
    if (op2_len <= 0)
        mx_error_invalid_operand(argv[3]);
    if (res_len <= 0)
        mx_error_invalid_result(argv[4]);

    for (int i = 0; i < op1_len; i++) {
        if (i == 0 && op1[i] == '-')
            continue;
        if (op1[i] != '?' && !mx_isdigit(op1[i]))
            mx_error_invalid_operand(argv[1]);
    }

    if (*operation != '?' && *operation != '+' && *operation != '-' &&
        *operation != '*' && *operation != '/') {
        mx_error_invalid_operation(argv[2]);
    }

    for (int i = 0; i < op2_len; i++) {
        if (i == 0 && op2[i] == '-')
            continue;
        if (op2[i] != '?' && !mx_isdigit(op2[i]))
            mx_error_invalid_operand(argv[3]);
    }
    for (int i = 0; i < res_len; i++) {
        if (i == 0 && res[i] == '-')
            continue;
        if (res[i] != '?' && !mx_isdigit(res[i]))
            mx_error_invalid_operand(argv[4]);
    }

    mx_print_equation(op1, operation, op2, res, op1_len, op2_len, res_len);

    free(op1);
    op1 = NULL;
    free(operation);
    operation = NULL;
    free(op2);
    op2 = NULL;
    free(res);
    res = NULL;
    return 0;
}

