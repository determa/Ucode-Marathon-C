#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 3 || (mx_strcmp(argv[1], "-p") != 0 
        && mx_strcmp(argv[1], "-s") != 0 && mx_strcmp(argv[1], "-n") != 0)) {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(0);
    }
    int num_arr = 0;
    int num_agent = 0;
    char buf;
    char last;
    bool space = false;
    int file = open(argv[2], O_RDONLY);
    if (file < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    while (read(file, &buf, 1)){
        if (buf == '{') {
            num_agent++;
        }
    } 
    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    t_agent **arr_agents = (t_agent **)malloc(num_agent * 16);
    for (int i = 0; i < num_agent; i++) {
        arr_agents[i] = (t_agent *)malloc(16);
    }
    char *a = mx_strnew(1000);
    int count = 0;
    file = open(argv[2], O_RDONLY);
    if (file < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    while (read(file, &buf, 1)) {
        if (buf == ' ' && last == ':') {
            space = true;
        }
        if (space && buf != '\n') {
            a[count++] = buf;
        }
        if (space && buf == '\n') {
            space = false;
            a[count++] = ' ';
        }
        last = buf;
    }
    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    char **arr = mx_strsplit(a, ' ');
    while(*arr) {
        num_arr++;
        arr++;
    }
    arr -= num_arr;

    int ind = 0;
    for (int i = 0; i < num_agent; i++) {
        arr_agents[i] -> name = arr[ind++];
        arr_agents[i] -> power = mx_atoi(arr[ind++]);
        arr_agents[i] -> strength = mx_atoi(arr[ind++]);
    }
    if (mx_strcmp(argv[1], "-p") == 0) {
        for (int i = 0; i < num_agent; i++) {
            for (int j = 0; j < num_agent - 1; j++) {
                if (arr_agents[j] -> power > arr_agents[j + 1] -> power) {
                    t_agent t_a = *arr_agents[j];
                    *arr_agents[j] = *arr_agents[j + 1];
                    *arr_agents[j + 1] = t_a;
                }
            }
        }
    }
    else if (mx_strcmp(argv[1], "-s") == 0) {
        for (int i = 0; i < num_agent; i++) {
            for (int j = 0; j < num_agent - 1; j++) {
                if (arr_agents[j] -> strength > arr_agents[j + 1] -> strength) {
                    t_agent t_a = *arr_agents[j];
                    *arr_agents[j] = *arr_agents[j + 1];
                    *arr_agents[j + 1] = t_a;
                }
            }
        }
    }
    else if (mx_strcmp(argv[1], "-n") == 0) {
        for (int i = 0; i < num_agent; i++) {
            for (int j = 0; j < num_agent - 1; j++) {
                if (mx_strcmp(arr_agents[j] -> name, arr_agents[j + 1] -> name) > 0) {
                    t_agent t_a = *arr_agents[j];
                    *arr_agents[j] = *arr_agents[j + 1];
                    *arr_agents[j + 1] = t_a;
                }
            }
        }
        
    }
    mx_print_agents(arr_agents, num_agent);
    for (int i = 0; i < num_agent; i++) {
        free(arr_agents[i]);
        arr_agents[i] = NULL;
    }
    free(arr_agents);
    arr_agents = NULL;
    while (arr[num_arr] != NULL) {
        free(arr[num_arr++]);
        arr[num_arr++] = NULL;
    }
    free(arr);
    arr = NULL;
    free(arr);
    arr = NULL;
    free(a);
    a = NULL;
    return 0;
}

