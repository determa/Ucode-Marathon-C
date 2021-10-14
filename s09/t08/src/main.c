#include "../inc/calculator.h"


int main(int argc, char *argv[]) {
    enum e_operation eop = -1;
    enum e_error eer = -1;
    t_operation top;

    if (argc != 4) {
        mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
        return 0;
    }

    int a = mx_atoi(argv[1]);
    char* b = argv[2];
    int c = mx_atoi(argv[3]);

    if (mx_strcmp(b, "-") == 0) {
        eop = SUB;
        top.op = eop;
        top.f = mx_sub;
    }
    else if (mx_strcmp(b, "+") == 0) {
        eop = ADD;
        top.op = eop;
        top.f = mx_add;
    }
    else if (mx_strcmp(b, "*") == 0) {
        eop = MUL;
        top.op = eop;
        top.f = mx_mul;
    }
    else if (mx_strcmp(b, "/") == 0) {
        eop = DIV;
        top.op = eop;
        top.f = mx_div;
    }
    else if (mx_strcmp(b, "%") == 0) {
        eop = MOD;
        top.op = eop;
        top.f = mx_mod;
    }
    else
        eer = INCORRECT_OPERATION;

    if (a == (0))
        eer = INCORRECT_OPERAND;
    else if (c == (00)) {
        if (eop == DIV)
            eer = DIV_BY_ZERO;
        else
            eer = INCORRECT_OPERAND;
    }

    if (eer == INCORRECT_OPERATION) {
        mx_printerr("error: invalid operation\n");
        return 0;
    }
    else if (eer == DIV_BY_ZERO) {
        mx_printerr("error: division by zero\n");
        return 0;
    }
    else if (eer == INCORRECT_OPERAND) {
        mx_printerr("error: invalid number\n");
        return 0;
    }

    int res = top.f(a, c);

    mx_printint(res);
    mx_printchar('\n');

    return 0;
}

