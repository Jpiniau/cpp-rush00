/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:36:59 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 11:45:57 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp" 

Frame::Frame(void) {
	WINDOW		*win;
	BaseShip	*BS;

	initscr();
	noecho();

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	win = newwin(75, 50, 0, 0);
	nodelay(win, TRUE);
	refresh();
	
	_win = win;

	BS = new BaseShip();

	_ptr = BS;
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
		mvwprintw(win, ptr.getY(), ptr.getX(), ptr.getAppearance().c_str());
	}
	wrefresh(win);
}

void            Frame::spawnRandomEnemy(void) {
    AEntity     *ptr;
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = ((rand() + salt++) % 2);
    if (val < 0 || val > 1)
        val = 0;
    switch (val) {
        case 0:
            ptr = new Meteor();
        break;
        case 1:
            ptr = new Mine();
        break;
    }
    
}

void            Frame::updateAll(void) {
	for (AEntity *ptr = this->_ptr; ptr != NULL; ptr = ptr->getNext())
		ptr->move();
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
