void mx_printchar(char c);
void mx_printint(int n);
int mx_atoi(char *str);

int main(int argc, char *argv[]) {
    if (argc == 1)
        return 0;
    int num = 0;
    int arr[32];
    for (int i = 1; i < argc; i++) {
        num  = mx_atoi(argv[i]);
        for (int i = 31; i >= 0; i--) {
            int k = num >> i;
            if (k & 1)
                arr[i] = 1;
            else
                arr[i] = 0;
        }
        for (int i = 31; i >= 0; i--)
            mx_printint(arr[i]);
        mx_printchar('\n');
    }
    return 0;
}

