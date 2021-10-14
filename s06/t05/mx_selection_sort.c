int mx_strcmp();
int mx_strlen();

int mx_selection_sort(char **arr, int size) {
    int j = 0;
    char *tmp;
    int count = 0;

    for (int i = 0; i < size; i++){
        j = i;
        for (int k = i; k < size; k++){
            if (mx_strlen(arr[j]) > mx_strlen(arr[k])){
                j = k;
            }
            if (mx_strlen(arr[j]) == mx_strlen(arr[k])) {
                if(mx_strcmp(arr[j], arr[k]) > 0) {
                    j = k;
                }
            }
        }
        if (j != i) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            count++;
        }
    }
    return count;
}

