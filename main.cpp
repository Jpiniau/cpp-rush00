#include <ncurses.h>
#include "Frame.hpp"

int main(void)
{	
/*	int		ch;
	WINDOW	*win;

	initscr();
	noecho();
	
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	win = newwin(50, 50, 0, 0);
	refresh();

	box(win, 0, 0);	
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 10, 10, "Player");
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 20, 20, "Enemy");
	
	wrefresh(win);
	
	ch = 0;
	nodelay(win, TRUE);
	while (1)
	{
		ch = wgetch(win);
		if (ch == 27)
			break;
		if (ch == 'e')
			mvwprintw(win, 10, 17, "--");
		wrefresh(win);
	}
	endwin();
*/

	new Frame();

	return 0;
}
