#include <ncurses.h>
#include "Frame.hpp"
#include "AEntity.hpp"
#include <iostream>
#include <ctime>
#include <stdio.h>


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

/*	for (int i =0; i < 500; i++)
	{
		Frame	*new_frame =	new Frame();
		std::cout << "here i = " << i << "and *new frame = "<< new_frame << std::endl;
		delete new_frame;
	}*/


	clock_t	this_time = clock();
	clock_t	last_time = this_time;

	double	time_counter = 0;

	Frame	*new_frame = new Frame();

	while (true) {
		this_time = clock();
		time_counter += (double) (this_time - last_time);
		last_time = this_time;
		if (time_counter > (double)( (5 / FRAME_RATE) * CLOCKS_PER_SEC)) {
			time_counter -= (double)( (5 / FRAME_RATE) * CLOCKS_PER_SEC);
			new_frame->updateAll();
			new_frame->generateFrame();
		}
	}

	return 0;
}
