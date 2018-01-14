/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mine.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:25:53 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 16:48:52 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Mine.hpp"
#include <cstdlib>
#include <ctime>

Mine::Mine(void) : AEntity("@", 75, 0, 2, 2, 0, 0, 50, 2, 2, false), AEnemy() {
	this->setRandSpeed();
	this->setRandCoord();
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
	this->setFrameAdvanceX(this->getFrameAdvanceX() + this->getSpeedX());
	this->setFrameAdvanceY(this->getFrameAdvanceY() + this->getSpeedY());
	if (ABS(this->getFrameAdvanceX()) >= FRAME_RATE) {
		this->setX(this->getX() + SIGNE(getFrameAdvanceX()));
		this->setFrameAdvanceX(this->getFrameAdvanceX() % FRAME_RATE);
	}
	if (ABS(this->getFrameAdvanceY()) >= FRAME_RATE) {
		this->setY(this->getY() + SIGNE(getFrameAdvanceY()));
		this->setFrameAdvanceY(this->getFrameAdvanceY() % FRAME_RATE);
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
