/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:50 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/14 18:43:07 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseShip.hpp"
#include <iostream>

BaseShip::BaseShip(void) : ASpaceShip(), APlayer(), AEntity(">", 5, 5, 0, 0, 0, 0, 50, 5, 0, false)
{
	return;
}

BaseShip::BaseShip(BaseShip const & src) : ASpaceShip(src), APlayer(src), AEntity(src)
{
	*this = src;
}

BaseShip::~BaseShip(void)
{
	AEntity::~AEntity();
	ASpaceShip::~ASpaceShip();
	APlayer::~APlayer();
	return;
}

void            BaseShip::colisionEffect(AEntity ** entity) {
/*    AEntity *ptr;

    ptr = *entity;
    ptr->getNext()->setPrev(ptr->getPrev());
    ptr->getPrev()->setNext(ptr->getNext());
    delete entity;*/
    (*entity)->setIsJustDestroyed(true);
    this->setIsJustDestroyed(true);
    return;
}

void	BaseShip::shoot(void)
{
	Projectile	*proj;
	AEntity		*list;

	list = this;
	while (list->getNext())
		list = list->getNext();
	//std::cout << this->getX() + 1 << std::endl;
	proj = new Projectile("-", this->getX() + 1, this->getY(), 10, 0, 0, 0, 0, 0, 0, 0, 10, 30);

	list->setNext(proj);
	proj->setPrev(list);
	proj->setNext(NULL);
}

void	BaseShip::detectInput(void)
{
	int		ch[4];
	int		i;

	i = -1;
	while (++i < 4)
	{
		ch[i] = getch();
	}
	this->setCH(ch, i);
}

void	BaseShip::setCoord(void)
{
	this->setX(5);
	this->setY(5);
	return;
}

BaseShip &	BaseShip::operator=(BaseShip const & rhs)
{
	AEntity::operator=(rhs);
	return (*this);
}

BaseShip	*BaseShip::factory(void) {
	BaseShip *new_BaseShip;

	new_BaseShip = new BaseShip();
	return (new_BaseShip);
}

void		BaseShip::move(void)
{
	//std::cout << this->getX() << std::endl;
	int *ch = getCH();
	int i;

	//std::cout << ch[0] << std::endl;
	i = -1;
	if (ch[0] == -1)
	{
		this->setSpeedY(0);
		this->setSpeedX(0);
	}
	while (++i < 4)
	{
		switch (ch[i])
		{
			case KEY_UP:
				if (getSpeedY() <= -5)
					setSpeedY(-5);
				else
					setSpeedY(-5);
			break;
			case KEY_DOWN:
				if (getSpeedY() >= 5)
					setSpeedY(5);
				else
					setSpeedY(5);
			break;
			case KEY_LEFT:
				if (getSpeedX() <= -5)
					setSpeedX(-5);
				else
					setSpeedX(-5);
			break;		
			case KEY_RIGHT:
				if (getSpeedX() >= 5)
					setSpeedX(5);
				else
					setSpeedX(5);
			break;
			case ' ':
				this->shoot();
			break;
			default:
				
			break;
		}
		ch[i] = -1;
	}
	//std::cout << "Speed x:" << this->getSpeedX() << std::endl <<  "Speed y:" << this->getSpeedY() << std::endl;
	//std::cout << "Frame advance x:" << this->getFrameAdvanceX() << std::endl <<  "Frame advance y:" << this->getFrameAdvanceY() << std::endl;
	this->setFrameAdvanceX(this->getFrameAdvanceX() + this->getSpeedX());
	this->setFrameAdvanceY(this->getFrameAdvanceY() + this->getSpeedY());

	if (ABS(this->getFrameAdvanceX()) >= FRAME_RATE) {
		this->setX(this->getX() + SIGNE(getFrameAdvanceX()));
		this->setFrameAdvanceX(this->getFrameAdvanceX() % FRAME_RATE);
		//std::cout << "1Coord x:" << this->getX() << "y:" << this->getY() << std::endl;
	}
	if (ABS(this->getFrameAdvanceY()) >= FRAME_RATE) {
		this->setY(this->getY() + SIGNE(getFrameAdvanceY()));
		this->setFrameAdvanceY(this->getFrameAdvanceY() % FRAME_RATE);
		//std::cout << "2Coord x:" << this->getY() << "y:" << this->getY();
	}

	return;
}

void		BaseShip::destructor(void){
	BaseShip::~BaseShip();
}
