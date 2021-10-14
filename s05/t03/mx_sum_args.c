int mx_atoi(char *str);
void mx_printint(int n);
void mx_printchar(char c);

int main(int argc, char *argv[]) {
    if (argc == 1)
        return 0;
    int sum = 0;
    for(int i = 1; i < argc; i++) {
        sum += mx_atoi(argv[i]);
    }
    mx_printint(sum);
    mx_printchar('\n');
    return 0;
}

