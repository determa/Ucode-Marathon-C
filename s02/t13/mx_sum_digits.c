int mx_sum_digits(int num) {
    int res = 0;
    while (num != 0) {
        res = res + num % 10;
        num = num / 10;
    }
    return res;
}
