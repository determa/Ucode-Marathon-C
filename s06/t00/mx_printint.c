void mx_printchar();

void mx_printint(int n) {
    int num = n;
    if (num < 0) {
        mx_printchar('-');
        num = num * -1;
    }
    if (num >= 10) {
        mx_printint(num / 10);
    }
    mx_printchar((num % 10) + 48);
}

