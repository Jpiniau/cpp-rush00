/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Meteor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:12:28 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 16:50:29 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Meteor.hpp"
#include <cstdlib>
#include <ctime>

Meteor::Meteor(void) : AEntity("#", 75, 45, 2, 2, 0, 0, 50, 2, 2, false), AEnemy() {
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
    int frame_advancementX = this->getFrameAdvanceX() + this->getSpeedX();
    int frame_advancementY = this->getFrameAdvanceY() + this->getSpeedY();

    if (ABS(frame_advancementX) >= this->getFrameRate()) {
        this->setX(this->getX() + SIGNE(frame_advancementX));
    }
    if (ABS(frame_advancementY) >= this->getFrameRate()) {
        this->setY(this->getY() + SIGNE(frame_advancementY));
    }
    return;
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
    this->setSpeedY(74);
}

Meteor &	Meteor::operator=(Meteor const &rhs)
{
	AEntity::operator=(rhs);
	return (*this);
}
