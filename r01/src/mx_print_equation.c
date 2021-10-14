#include "../inc/part_of_the_matrix.h"

void mx_print_equation(char *op1, char *operation, char *op2, char *res, 
                       int op1_len, int op2_len, int res_len) {

    if (*operation == '?') {
        mx_print_equation(op1, "+", op2, res, op1_len, op2_len, res_len);
        mx_print_equation(op1, "-", op2, res, op1_len, op2_len, res_len);
        mx_print_equation(op1, "*", op2, res, op1_len, op2_len, res_len);
        mx_print_equation(op1, "/", op2, res, op1_len, op2_len, res_len);
        return;
    }

    bool op1Negative = false;
    bool op2Negative = false;
    bool resNegative = false;

    if (op1[0] == '-') {
        op1Negative = true;
        op1++;
        op1_len--;
    } 
    if (op2[0] == '-') {
        op2Negative = true;
        op2++;
        op2_len--;
    }
    if (res[0] == '-') {
        resNegative = true;
        res++;
        res_len--;
    }

    long long number1 = mx_atoi(op1);
    long long number2 = mx_atoi(op2);
    long long number3 = mx_atoi(res);

    for (long long i = 0; i < mx_pow(10, op1_len); i++) {
        if (number1 > 0)
            i = number1;

        char *i_str = mx_itoa(i);
        int i_str_len = mx_strlen(i_str);

        bool iCorrect = true;

        for (int j = 0; j < op1_len - i_str_len; j++) {
            if (mx_isdigit(op1[j]) && op1[j] != '0') {
                iCorrect = false;
                break;
            }
        }

        for (int j = op1_len - i_str_len, i_str_i = 0; j < op1_len; j++, i_str_i++) {
            if (op1[j] != '?' && op1[j] != i_str[i_str_i]) {
                iCorrect = false;
                break;
            }
        }

        free(i_str);
        i_str = NULL;

        if (!iCorrect)
            continue;

        for (long long j = 0; j < mx_pow(10, op2_len); j++) {  
            if (number2 > 0)
                j = number2;

            char *j_str = mx_itoa(j);
            int j_str_len = mx_strlen(j_str);
            bool jCorrect = true;

            for (int j_i = 0; j_i < op2_len - j_str_len; j_i++) {
                if (mx_isdigit(op2[j_i]) && op2[j_i] != '0') {
                    jCorrect = false;
                    break;
                }
            }

            for (int j_i = op2_len - j_str_len, j_str_i = 0;
                 j_i < op2_len; j_i++, j_str_i++) {
                if (op2[j_i] != '?' && op2[j_i] != j_str[j_str_i]) {
                    jCorrect = false;
                    break;
                }
            }

            free(j_str);
            j_str = NULL;

            if (!jCorrect)
                continue;
            
            for (long long k = 0; k < mx_pow(10, res_len); k++) {
                if (number3 > 0)
                    k = number3;

                char *k_str = mx_itoa(k);
                int k_str_len = mx_strlen(k_str);
                bool kCorrect = true;

                for (int k_i = 0; k_i < res_len - k_str_len; k_i++) {
                    if (mx_isdigit(res[k_i]) && res[k_i] != '0') {
                        kCorrect = false;
                        break;
                    }
                }

                for (int k_i = res_len - k_str_len, k_str_i = 0;
                     k_i < res_len; k_i++, k_str_i++) {
                    if (res[k_i] != '?' && res[k_i] != k_str[k_str_i]) {
                        kCorrect = false;
                        break;
                    }
                }

                free(k_str);
                k_str = NULL;

                if (!kCorrect)
                    continue;

                if (op1Negative)
                    i *= -1;
                if (op2Negative)
                    j *= -1;
                if (resNegative)
                    k *= -1;

                if (*operation == '+') {
                    if (i + j == k)
                        mx_print_res(i, " + ", j, k);
                }
                else if (*operation == '-') {
                    if (i - j == k)
                        mx_print_res(i, " - ", j, k);
                }
                else if (*operation == '*') {
                    if (i * j == k)
                        mx_print_res(i, " * ", j, k);
                }
                else if (*operation == '/') {
                    if (j != 0 && i / j == k)
                        mx_print_res(i, " / ", j, k);
                }
                
                if (op1Negative)
                    i *= -1;
                if (op2Negative)
                    j *= -1;
                if (resNegative)
                    k *= -1;
                if (number3 > 0)
                    break;
            }
            if (number2 > 0)
                break;
        }
        if (number1 > 0)
            break;
    }

    if (op1Negative)
        op1--;
    if (op2Negative)
        op2--;
    if (resNegative)
        res--;
}

