/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mine.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:25:53 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 16:52:30 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Mine.hpp"
#include <cstdlib>
#include <ctime>

Mine::Mine(void) : AEntity("@", 45, 45, 2, 2, 0, 0, 50, 2, 2, false), AEnemy() {
    return;
}

Mine::Mine(Mine const & src) : AEntity(src), AEnemy(src)  {
    *this = src;
}

Mine::~Mine(void) {
    if (this->getX() >= 0 && this->getX() < 75 && this->getY() >= 0 && this->getY() < 0)
        this->spawnMeteor();
    AEntity::~AEntity();
}

Mine &          Mine::operator=(Mine const & rhs) {
    AEntity::operator=(rhs);
    return (*this);
}

void            Mine::colisionEffect(AEntity ** entity) {
/*    AEntity *ptr;

    ptr = *entity;
    ptr->getNext()->setPrev(ptr->getPrev());
    ptr->getPrev()->setNext(ptr->getNext());
    delete entity;*/
    (*entity)->setIsJustDestroyed(true);
    this->setIsJustDestroyed(true);
    return;
}

void            Mine::move(void) {
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

void            Mine::patern(void) {
    return;
}

Mine	*Mine::factory(void) {
	Mine *new_Mine;

	new_Mine = new Mine();
	return (new_Mine);
}

void            Mine::setRandSpeed(void) {
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = ((rand() + salt++) % 4) + 1;
    this->setSpeedX(-val);
    val = ((rand() + salt++) % 11) - 5;
    this->setSpeedY(val);
}

void            Mine::setRandCoord(void) {
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = (rand() + salt++) % 40;
    this->setY(val + 5);
    this->setSpeedY(74);
}

void            Mine::spawnMeteor(void) {
	Meteor      *meteor;
	AEntity		*list;

	list = this;
	while (list->getNext())
		list = list->getNext();

	meteor = new Meteor(this->getX(), this->getY());
	
	list->setNext(meteor);
	meteor->setPrev(list);
	meteor->setNext(NULL);
}
