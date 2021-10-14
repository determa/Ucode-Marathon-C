#include "matrix.h"

void mx_print_text(WINDOW *mainwin, int colums, int rows) {
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wbkgd(mainwin, COLOR_PAIR(3));

    if (colums > 16 && rows > 32) {
        int x = colums / 8;
        int y = rows / 64;

        usleep(15000);

        char t1[] = "Wake up , Neo..";
        char t2[] = "The Matrix has you..";
        char t3[] = "Follow the white rabbit";
        char t4[] = "Knock, knock, Neo";

        wclear(mainwin);
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;

        while(a < 15) {
            mvwaddch(mainwin, y, x + a, t1[a]);
            refresh();
            usleep(150000);
            a++;
        }

        wclear(mainwin);
        usleep(100000);

        while(b < 20) {
            mvwaddch(mainwin, y, x + b, t2[b]);
            refresh();
            usleep(150000);
            b++;
        }

        wclear(mainwin);
        usleep(100000);

        while (c < 23) {
            mvwaddch(mainwin, y, x + c, t3[c]);
            refresh();
            usleep(150000);
            c++;
        }
        wclear(mainwin);
        usleep(100000);

        while(d < 17) {
            mvwaddch(mainwin, y, x + d, t4[d]);
            refresh();
            usleep(150000);
            d++;
        }
    }
}

