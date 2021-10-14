void mx_printstr(const char *s);
void mx_printchar(char c);
char *mx_strchr(const char *s, int c);

int main(int argc, char *argv[]) {
    argc = 0;
    mx_printstr(mx_strchr(argv[0], '/') + 1);
    mx_printchar('\n');
    return 0;
}

