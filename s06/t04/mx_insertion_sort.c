int mx_strlen();

int mx_insertion_sort(char **arr, int size) {
    char *key;
    int i = 0;
    int count = 0;
    for(int j = 1; j < size; j++){
        key = arr[j];
        i = j-1;
        while(i >= 0 && mx_strlen(arr[i]) > mx_strlen(key)){
            count++;
            arr[i + 1] = arr[i];
            i = i - 1;
            arr[i + 1]= key;
        }
    }
    return count;
}

