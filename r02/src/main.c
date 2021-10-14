#include "../inc/header.h"

int lee(const char *filename, int x1, int y1, int x2, int y2) {
    char temp;
    int line = 0;
    int column = 0;
    bool flag = false;
    //-----------counters--------------
    int fd = open (filename, O_RDONLY);
    if (fd < 0)
        return -1;
    while (read (fd, &temp, 1) > 0) {
        if (temp =='\n') {
            line++;
            flag = true;
        }
        if (temp != ',' && flag != true) {
            column++;
        }
    }
    if (close (fd) != 0)
        return -1;
    close (fd);
    //-----------char to array---------
    char arr[line][column];
    int int_arr[line][column];

    int i = 0;
    int j = 0;

    fd = open (filename, O_RDONLY);
    if (fd < 0)
        return -1;
    while (read (fd, &temp, 1) > 0) {
        if (temp != ',' && temp !='\n') {
            arr[i][j] = temp;
            if (temp == '#')
                int_arr[i][j] = -1;
            if (temp == '.')
                int_arr[i][j] = -2;
            j++;
        }
        if (temp =='\n') {
            i++;
            j = 0;
        }
    }
    if (close (fd) != 0)
        return -1;
    close (fd);
    //-------------------------------------------------------
    int wall = -1;  // стенка
    int blank = -2; // свободная непомеченная ячейка
    if (int_arr[y1][x1] == wall) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(-1);
    }
    if (int_arr[y2][x2] == wall) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(-1);
    }
    int d = 0, k;
    int_arr[y1][x1] = 0;
    bool stop = false;
    bool found = false;
    int flag1 = 1;
    int dx[4] = {1, 0, -1, 0};   // смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1};  // справа, снизу, слева и сверху
    while (!stop || flag1) {
        stop = true;
        for (i = 0; i < line; ++i) {
            for (j = 0; j < column; ++j) {
                if (int_arr[i][j] == d) {
                    if (j == x2 && i == y2)
                        found = true;
                    for (k = 0; k < 4; ++k) {
                        int iy = i + dy[k], ix = j + dx[k];
                        
                        if (iy >= 0 && iy < line && ix >= 0 && ix < column 
                            && int_arr[iy][ix] == blank) {
                            stop = false;
                            int_arr[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }
        d++;
        flag1 = 0;
    }

    if(found == false) {
        mx_printerr("route not found\n");
        exit(-1);
    }

    int len = int_arr[y2][x2];
    int px[line * column], py[line * column];
    int x = x2;
    int y = y2;
    int last_num = d - 1;
    d = len;

    while (d > 0) {
        px[d] = x;
        py[d] = y;
        d--;
        for (int k = 0; k < 4; ++k) {
            int iy = y + dy[k], ix = x + dx[k];
            if (iy >= 0 && iy < line && ix >= 0 && ix < column
                && int_arr[iy][ix] == d) {
                x = x + dx[k];
                y = y + dy[k];
                break;
            }
        }
    }

    px[0] = x1;
    py[0] = y1;
    for(int i = 0; i <= len; i++) {
        arr[py[i]][px[i]] = '*';
    }

    for (i = 0; i < line; i++) {
        for (j = 0; j < column; j++) {
            if (int_arr[i][j] == last_num) {
                arr[i][j] = 'D';
                if (y2 == i && x2 == j) {
                    arr[i][j] = 'X';
                }
            }
        }
    }
    int output = open("path.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (output < 0)
        return -1;
    for (i = 0; i < line; i++) {
        for (j = 0; j < column; j++) {
            write(output, &arr[i][j], 1);
        }
        write(output, "\n", 1);
    }
    if (close (output) != 0)
        return -1;
    close (output);
    mx_printstr("dist="); 
    mx_printint(last_num);
    mx_printstr("\nexit=");
    mx_printint(len);
    mx_printchar('\n');
    return 0;
}

int main(int argc, char *argv[]) {
    error_list(argc, argv);
    lee(argv[1], mx_atoi(argv[2]), mx_atoi(argv[3]), mx_atoi(argv[4]), mx_atoi(argv[5]));
    return 0;
}

