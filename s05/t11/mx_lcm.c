int mx_gcd(int a, int b);

int mx_lcm(int a, int b) {
    long long int res = ((long)a * b) / mx_gcd(a, b);
    if (res >= 2147483647 || res <= -2147483648)
        return 0;
    return res;
}

