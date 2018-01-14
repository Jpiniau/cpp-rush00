/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:36:59 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 17:14:30 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp" 
#include <iostream>

Frame::Frame(void) {
	WINDOW		*win;
	BaseShip	*BS;

	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	win = newwin(50, 75, 0, 0);
	nodelay(win, TRUE);
	keypad(win, TRUE);
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
	WINDOW			*win;

	win	= _win;

	werase(win);
	for (AEntity *ptr = this->_ptr; ptr != NULL; ptr = ptr->getNext())
	{
		if (ptr->getAllegiance() == 0)
			wattron(win, COLOR_PAIR(1));
		else
			wattron(win, COLOR_PAIR(2));
		mvwprintw(win, ptr->getY(), ptr->getX(), ptr->getAppearance().c_str());
	}
	wrefresh(win);
}

void            Frame::spawnRandomEnemy(void) {
    AEntity     *ptr;
	AEntity		*list;
    static int	salt = rand() + 7;
    int			val = ((rand() + salt++) % 2);

	list = _ptr;
    srand(time(NULL));
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
	if (val == 0 || val == 1)
	{
		while (list->getNext())
			list= list->getNext();
		list->setNext(ptr);
		ptr->setPrev(list);
		ptr->setNext(NULL);
	}
}

void            Frame::updateAll(void) {
	int i;
	int	newCH[4];
	AEntity *ptr = this->_ptr;
	
	i = -1;
	while (++i < 4)
		newCH[i] = wgetch(this->getWin());
	ptr->setCH(newCH, 4);
	for (; ptr != NULL; ptr = ptr->getNext())
	{
		ptr->move();
		if (ptr->getIsJustDestroyed() == 1)
		{
			if (ptr->getPrev() != NULL)
				ptr->getPrev()->setNext(ptr->getNext());
			if (ptr->getNext() != NULL)
				ptr->getNext()->setPrev(ptr->getPrev());
			ptr->destructor();
		}
	}
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
