void mx_printchar(char c);

void mx_cube(int n) {
    if(n > 1) {
        for (int i = 0; i < n / 2 + 1; i++)
            mx_printchar(' ');
        mx_printchar('+');
        for (int i = 0; i < 2 * n; i++)
            mx_printchar('-');
        mx_printchar('+');
        mx_printchar('\n');
        for (int i =  0; i < n / 2; i++) {
            for (int j = i; j < n / 2; j++)
                mx_printchar(' ');
            mx_printchar('/');
            for (int i = 0; i < 2 * n; i++)
                mx_printchar(' ');
            mx_printchar('/');
            for (int k = 0; k < i; k++)
                mx_printchar(' ');
            mx_printchar('|'); 
            mx_printchar('\n');
        }
        mx_printchar('+');
        for (int i = 0; i < 2 * n; i++)
            mx_printchar('-');
        mx_printchar('+');

        for (int k = 0; k < n / 2; k++)
            mx_printchar(' ');
        mx_printchar('|'); 
        mx_printchar('\n');
        for (int i =  0; i < (n - 1) / 2; i++) {
            mx_printchar('|');
            for (int i = 0; i < 2 * n; i++)
                mx_printchar(' ');
            mx_printchar('|');
            for (int k = 0; k < n / 2; k++)
                mx_printchar(' ');
            mx_printchar('|'); 
            mx_printchar('\n');
        }

        mx_printchar('|');
        for (int i = 0; i < 2 * n; i++)
            mx_printchar(' ');
        mx_printchar('|');
        for (int k = 0; k < n / 2; k++)
            mx_printchar(' ');
        mx_printchar('+');
        mx_printchar('\n');

        for (int i =  0; i < n / 2; i++) {
            mx_printchar('|');
            for (int i = 0; i < 2 * n; i++)
                mx_printchar(' ');
            mx_printchar('|');
            for (int j = 1; j < (n / 2) - i; j++)
                mx_printchar(' ');
            mx_printchar('/'); 
            mx_printchar('\n');
        }
        mx_printchar('+');
        for (int i = 0; i < 2 * n; i++)
            mx_printchar('-');
        mx_printchar('+');
        mx_printchar('\n');
    }
}

