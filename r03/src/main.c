#include "matrix.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "ja_JP.UTF-8");

	WINDOW* mainwin = initscr();

	curs_set(false);

	mx_matrix(mainwin, argc, argv);
	
	delwin(mainwin);

	endwin();

	return 0;
}

