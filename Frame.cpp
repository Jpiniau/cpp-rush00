/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:36:59 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 20:15:46 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp" 

Frame::Frame(void) {
	WINDOW	*win;

	initscr();
	noecho();

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	win = newwin(75, 50, 0, 0);
	nodelay(win, TRUE);
	refresh();
	
	_win = win;

    return;
}

Frame::Frame(Frame const & src) {
    *this = src;
}

Frame::~Frame(void) {
	return;
}

Frame &         Frame::operator=(Frame const & rhs) {
    this->setPtr(rhs.getPtr());
    this->setWin(rhs.getWin());
    return (*this);
}

void            Frame::generateFrame(void) {

	AEntity	const	&ptr = getPtr();
	WINDOW			*win;

	win	= _win;

	while (ptr.getNext())
	{
		if (ptr.getAllegiance() == 0)
			wattron(win, COLOR_PAIR(1));
		else
			wattron(win, COLOR_PAIR(2));
		mvwprintw(win, ptr.getY(), ptr.getX(), ptr.getAppearance());
	}
	wrefresh(win);
}

void            Frame::spawnRandomEnemy(void) {

}

void            Frame::updateAll(void) {
    
}

//getteurs
AEntity const & Frame::getPtr(void) const {	return (*(this->_ptr));}
WINDOW * Frame::getWin(void) const {	return (this->_win);}

//setteurs
void            Frame::setPtr(AEntity const & entity) {
    *(this->_ptr) = entity;
}

void			Frame::setWin(WINDOW * win) {
    this->_win = win;
}
