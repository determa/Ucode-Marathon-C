int mx_atoi(char *str) {
    int res = 0;
    int negative = 1;
    if (*str == '-') {
        negative = -1;
        str++;
    }
    while ((*str >= 48 && *str <= 57) ) {
      res = res * 10;
      res = res + (*str - 48);
      str++;
    }
    return (negative * res);
}

