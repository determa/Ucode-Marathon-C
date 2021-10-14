#include "../inc/header.h"

void error_list(int argc, char* argv[]) {
    //____________ argc err
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(-1);
    }
    //____________ error on fileError
    if (!argv[1]) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    //_________________ error on rectengle and symbols 
    int file = open(argv[1], O_RDONLY);
    char ch;
    int count_str = 0;
    int count_str_ex = 0;
    int count_y = 0;
    int flag = 0;
    while (read(file, &ch, 1)) {
        if (ch != '#' && ch != ',' && ch != '.' && ch != '\n') {
            mx_printerr("map error\n");
            exit(-1);
        }
        if (ch == ',')
            continue;
        count_str++;
        if (flag == 0) {
            count_str_ex++;
        }
        if (ch == '\n') {
            count_y++;
            flag = 1;
            if (count_str != count_str_ex) {
                mx_printerr("map error\n");
                exit(-1);
            }
            count_str = 0;
        }
    }
    //____________error in x and y
    if (mx_atoi(argv[2]) > count_str_ex || mx_atoi(argv[3]) > count_y 
        || mx_atoi(argv[4]) > count_str_ex || mx_atoi(argv[5]) > count_y
        || mx_atoi(argv[2]) < 0 || mx_atoi(argv[3]) < 0 || mx_atoi(argv[4]) < 0 
        || mx_atoi(argv[5]) < 0) {
        
        mx_printerr("points are out of map range\n");
        exit(-1);
    }
}

