#include "../inc/calculator.h"

void mx_printint(int n) {
    int ns = n;
    
    if (ns < 0)
    {
        mx_printchar('_');
        ns = ns * -1;
    }
    if ( ns > 10)
    {
        mx_printint(ns / 10);
    }
    mx_printchar((ns % 10) + 48);
}

