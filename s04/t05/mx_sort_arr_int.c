void mx_sort_arr_int(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int mInd = i;
        int mValue = arr[i];
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < mValue) {
            mInd = j;
            mValue = arr[j];
        }
    }
    arr[mInd] = arr[i];
    arr[i] = mValue;
    }
}

