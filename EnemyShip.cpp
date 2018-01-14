/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:15:58 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 20:00:21 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyShip.hpp"
#include <iostream>

EnemyShip::EnemyShip(void) : AEntity("<", 5, 5, 0, 0, 0, 0, 50, 5, 1, false), AEnemy(), ASpaceShip(), _canonCharge(0), _canonChargeLevel(4)
{
	this->setRandSpeed();
	this->setRandCoord();
	return;
}

EnemyShip::EnemyShip(EnemyShip const & src) : AEntity(src), AEnemy(src), ASpaceShip(src) , _canonCharge(0), _canonChargeLevel(4) 
{
	*this = src;
}

EnemyShip::~EnemyShip(void)
{
	AEntity::~AEntity();
	ASpaceShip::~ASpaceShip();
	AEnemy::~AEnemy();
	return;
}

void            EnemyShip::colisionEffect(AEntity ** entity) {
    AEntity *ptr;

    ptr = *entity;
    /*ptr->getNext()->setPrev(ptr->getPrev());
    ptr->getPrev()->setNext(ptr->getNext());
    delete entity;*/
	if (ptr->getAllegiance() == this->getAllegiance())
		return;
    (*entity)->setIsJustDestroyed(true);
    this->setIsJustDestroyed(true);
    return;
}

void	EnemyShip::shoot(void)
{
	Projectile	*proj;
	AEntity		*list;

	list = this;
	while (list->getNext())
		list = list->getNext();
	//std::cout << this->getX() + 1 << std::endl;
	proj = new Projectile("-", this->getX() - 1, this->getY(), -10, 0, 0, 0, 0, 0, 1, false, 2, 30);
	list->setNext(proj);
	proj->setPrev(list);
	proj->setNext(NULL);
}

EnemyShip &	EnemyShip::operator=(EnemyShip const & rhs)
{
	AEntity::operator=(rhs);
	return (*this);
}

EnemyShip	*EnemyShip::factory(void) {
	EnemyShip *new_EnemyShip;

	new_EnemyShip = new EnemyShip();
	return (new_EnemyShip);
}

void		EnemyShip::move(void)
{
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
    if (this->getCanonChargeLevel() >= this->getCanonCharge()) {
        this->setCanonChargeLevel(0);
        this->shoot();
    }
    else {
        this->setCanonChargeLevel(this->getCanonChargeLevel() + 1);
    }
	return;
}

void            EnemyShip::patern(void) {
    return;
}

void            EnemyShip::setRandSpeed(void) {
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = ((rand() + salt++) % 4) + 1;
    this->setSpeedX(-val);
    val = ((rand() + salt++) % 11) - 5;
    this->setSpeedY(0);
}

void            EnemyShip::setRandCoord(void) {
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = (rand() + salt++) % 40;
    this->setY(val + 5);
    this->setX(74);
}

void		EnemyShip::destructor(void){
	EnemyShip::~EnemyShip();
}

int         EnemyShip::getCanonCharge(void)         {   return (this->_canonCharge);}
int         EnemyShip::getCanonChargeLevel(void)    {   return (this->_canonChargeLevel);}

void        EnemyShip::setCanonCharge(int val){
    this->_canonCharge = val;
}

void        EnemyShip::setCanonChargeLevel(int val){
    this->_canonChargeLevel = val;
}
