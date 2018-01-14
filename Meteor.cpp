/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Meteor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:12:28 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 17:29:30 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Meteor.hpp"
#include <cstdlib>
#include <ctime>

Meteor::Meteor(void) : AEntity("#", 75, 45, 0, 0, 0, 0, 50, 2, 2, false), AEnemy() {
	this->setRandSpeed();
	this->setRandCoord();
	return;
}

Meteor::Meteor(int x, int y) : AEntity("#", x, y, 2, 2, 0, 0, 50, 2, 2, false), AEnemy() {
    return;
}

Meteor::Meteor(Meteor const & src) : AEntity(src) {
    *this = src;
}

Meteor::~Meteor(void) {
    AEntity::~AEntity();
}

void            Meteor::colisionEffect(AEntity ** entity) {
/*    AEntity *ptr;

    ptr = *entity;
    ptr->getNext()->setPrev(ptr->getPrev());
    ptr->getPrev()->setNext(ptr->getNext());
    delete entity;*/
    (*entity)->setIsJustDestroyed(true);
    this->setIsJustDestroyed(true);
    return;
}

void            Meteor::move(void) {
	this->setFrameAdvanceX(this->getFrameAdvanceX() + this->getSpeedX());
	this->setFrameAdvanceY(this->getFrameAdvanceY() + this->getSpeedY());
	if (ABS(this->getFrameAdvanceX()) >= FRAME_RATE) {
        if (this->getX() + SIGNE(getFrameAdvanceX()) >= 75 || this->getX() + SIGNE(getFrameAdvanceX()) < 0)
			this->setIsJustDestroyed(true);
		this->setX(this->getX() + SIGNE(getFrameAdvanceX()));
		this->setFrameAdvanceX(this->getFrameAdvanceX() % FRAME_RATE);
	}
	if (ABS(this->getFrameAdvanceY()) >= FRAME_RATE) {
        if (this->getY() + SIGNE(getFrameAdvanceY()) >= 50 || this->getY() + SIGNE(getFrameAdvanceY()) < 0)
            this->setIsJustDestroyed(true);
		this->setY(this->getY() + SIGNE(getFrameAdvanceY()));
		this->setFrameAdvanceY(this->getFrameAdvanceY() % FRAME_RATE);
	}
}

Meteor	*Meteor::factory(void) {
	Meteor *new_Meteor;

	new_Meteor = new Meteor();
	return (new_Meteor);
}

void            Meteor::patern(void) {
    return;
}

void            Meteor::setRandSpeed(void) {
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = ((rand() + salt++) % 4) + 1;
    this->setSpeedX(-val);
    val = ((rand() + salt++) % 11) - 5;
    this->setSpeedY(val);
}

void            Meteor::setRandCoord(void) {
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = (rand() + salt++) % 40;
    this->setY(val + 5);
    this->setX(74);
}

void	Meteor::destructor(void) {
	Meteor::~Meteor();
}

Meteor &	Meteor::operator=(Meteor const &rhs)
{
	AEntity::operator=(rhs);
	return (*this);
}
