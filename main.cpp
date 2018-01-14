#include <ncurses.h>
#include "Frame.hpp"
#include "AEntity.hpp"
#include <iostream>
#include <ctime>
#include <stdio.h>


int main(void)
{	
	clock_t	this_time = clock();
	clock_t	last_time = this_time;

	double	time_counter = 0;

	Frame	*new_frame = new Frame();

	while (new_frame->getEndOfGame() == 0) {
		this_time = clock();
		time_counter += (double) (this_time - last_time);
		last_time = this_time;
		if (time_counter > (double)( (0.1) * CLOCKS_PER_SEC)) {
			time_counter -= (double)( (0.1) * CLOCKS_PER_SEC);
			new_frame->updateAll();
			new_frame->generateFrame();
			new_frame->spawnRandomEnemy();
		}
	}
	std::cout << "YOU LOSE" << std::endl;

	return 0;
}
