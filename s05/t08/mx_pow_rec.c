double mx_pow_rec(double n, unsigned int pow) {
    if (pow == 0) return 1;
    if (pow < 0) return mx_pow_rec(10 / n, -pow);
    return n * mx_pow_rec(n, pow -1);
}

