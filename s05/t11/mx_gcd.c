int mx_gcd(int a, int b) {
    int rem = a % b;
    if(b < 0)
        b *= -1;
    if (rem == 0) {
        return b;
    }
    return mx_gcd(b, rem);
}

