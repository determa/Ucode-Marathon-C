void mx_printchar();

void mx_printint(int n) {
    int num = n;
    int count = 0;
    while (n != 0) {
        count++;
        n = n / 10;
    }
    char s[count];
    n = num;
    for(int i = 0; n != 0; i++) {
        s[i] = n % 10;
        n = n / 10;
    }
    for(int i = count - 1; i >= 0; i--)
        mx_printchar(s[i] + 48);
}
