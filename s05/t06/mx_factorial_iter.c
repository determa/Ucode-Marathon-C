int mx_factorial_iter(int n) {
    if (n < 0)
        return 0;
    long int res = 1;
    for (int i = 1; i <= n; i++){
        res *= i;
    }
    if (res >= 2147483647 || res <= -2147483648)
        return 0;
    return res;
}

