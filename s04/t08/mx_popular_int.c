int mx_popular_int(const int *arr, int size) {
	int x = 0, num = 0;
	for (int i = 0; i < size; i++) {
		int curr_num = arr[i], current_x = 0;
		for (int j = 0; j < size; j++) {
			if (arr[j] == curr_num)
				current_x++;
		}
		if (current_x > x) {
			x = current_x;
			num = curr_num;
		}
	}
	return num;
}

