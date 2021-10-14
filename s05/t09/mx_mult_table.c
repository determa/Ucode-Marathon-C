void mx_printchar(char c);
void mx_printint(int n);
int mx_atoi(char *str);

int main(int argc, char *argv[]) {
    if (argc <= 2 || argc > 3)
        return 0;
    int num1 = mx_atoi(argv[1]);
    int num2 = mx_atoi(argv[2]);
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    for (int i = num1; i <= num2; i++) {
        for (int j = num1; j <= num2; j++) {
            mx_printint(i * j);
            if (j != num2)
                mx_printchar('\t');
        }
        mx_printchar('\n');
    }
    return 0;
}

