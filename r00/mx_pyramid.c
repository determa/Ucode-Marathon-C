void mx_printchar(char c);

void mx_pyramid(int n) {
    if(n > 1 && n % 2 == 0) {
        int back = 0;
        for (int i = 0; i < n - 1; i++)
            mx_printchar(' ');
        mx_printchar('/');
        mx_printchar('\\');
        mx_printchar('\n');
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j < n - i - 1; j++)
                mx_printchar(' ');
            mx_printchar('/');
            for (int j = 1; j < 2 * i; j++)
                mx_printchar(' ');
            mx_printchar('\\');
            if (back < (n / 2) - 1) {
                for (int j = 0; j < i; j++)
                    mx_printchar(' ');
                mx_printchar('\\');
            } else {
                for (int j = 1; j < n - back - 1; j++)
                    mx_printchar(' ');
                mx_printchar('|');
            }
            back++;
            mx_printchar('\n');
        }
        mx_printchar('/');
        for (int i = 0; i < 2 * n - 3; i++)
            mx_printchar('_');
        mx_printchar('\\');
        mx_printchar('|');
        mx_printchar('\n');
    }
}

