int mx_mid(int a, int b, int c) {
    if ((a <= b && a >= c) || (a >= b && a <= c)) {
        return a;
    }
    else if ((b <= a && b >= c) || (b >= a && b <= c)) {
        return b;
    }
    else
        return c;
}
