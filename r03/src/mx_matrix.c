#include "matrix.h"

void mx_matrix(WINDOW *mainwin, int argc, char *argv[]) {
	int SPEED = 10;
	int rows;
	int cols;
	int color = 2;

	getmaxyx(mainwin, cols, rows);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(14, COLOR_YELLOW, COLOR_BLACK);
	init_pair(12, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);

	curs_set(false);
	noecho();

	t_display *matrix = (t_display *) malloc(sizeof(t_display) * rows);
	
	for (int i = 0; i < rows; i++) {
		matrix[i].arr = (wchar_t *) malloc(sizeof(wchar_t) * cols);

		for (int j = 0; j < cols; j++)
			matrix[i].arr[j] = mx_japanese();

		matrix[i].len = rand() % cols;
		matrix[i].start = 0 - matrix[i].len - matrix[i].len;
		matrix[i].finish = 0 - matrix[i].len;
	}

	wbkgd(mainwin, COLOR_PAIR(color));

	wclear(mainwin);

	if (argc != 2 || (argc == 2 && mx_strcmp(argv[1], "-s") != 0))
		mx_print_text(mainwin, cols, rows);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i].arr[j] = mx_japanese();

	while(true) {
		wtimeout(mainwin, 60 / SPEED * 10);

		switch(getch()) {
			case '-':
				if (SPEED > 10)
					SPEED -= 5;
				break;
			case '+':
				if (SPEED < 40)
					SPEED += 5;
				break;
			case '1':
				color = 2;
				break;
			case '2':
				color = 14;
				break;
			case '3':
				color = 12;
				break;
			case '4':
				color = 5;
				break;
			case '5':
				color = 6;
				break;
			case '6':
				color = 7;
				break;
			case 'q':
				exit(0);
		}

		wclear(mainwin);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (j >= matrix[i].start && j <= matrix[i].finish ) {
					if (j == matrix[i].finish) {
						attroff(COLOR_PAIR(color));
						attron(COLOR_PAIR(1));
					}

					mvprintw(j, i * 2, "%lc", matrix[i].arr[j]);

					if (j == matrix[i].finish) {
						attroff(COLOR_PAIR(1));
						attron(COLOR_PAIR(color));
					}
					if (j == matrix[i].start)
						matrix[i].arr[j] = mx_japanese();
					if (j == matrix[i].finish)
						matrix[i].arr[j] = mx_japanese();
				}
			}

			matrix[i].start++;
			matrix[i].finish++;
			
			if (matrix[i].start > cols) {
				matrix[i].len = rand() % cols;
				matrix[i].start = 0 - matrix[i].len - matrix[i].len;
				matrix[i].finish = 0 - matrix[i].len;
			} 
		}
		refresh();
	}

	for(int i = 0; i < cols; i++)
		free(matrix[i].arr);
	
	free(matrix);
	matrix = NULL;
}

