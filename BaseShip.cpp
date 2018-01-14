/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:50 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/14 11:02:28 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseShip.hpp"

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

	proj = new Projectile("-", this->getX() + 1, this->getY(), 5, 0, 0, 0, 0, 0, 0, 0, 10, 20);

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

void		BaseShip::setCH(int	*ch, int len) {
	while (--len > 0)
		this->_ch[len] = ch[len];
}

int			*BaseShip::getCH(void) {
	return ((this->_ch));
}

BaseShip	*BaseShip::factory(void) {
	BaseShip *new_BaseShip;

	new_BaseShip = new BaseShip();
	return (new_BaseShip);
}

void		BaseShip::move(void)
{
	int frame_advancementX;
	int frame_advancementY;
	int *ch = getCH();
	int i;

	i = -1;
	while (++i < 4)
	{
		switch (ch[i])
		{
			case KEY_UP:
				if (getSpeedY() <= -5)
					setSpeedY(-5);
				else
					setSpeedY(getSpeedY() - 1);
			case KEY_DOWN:
				if (getSpeedY() >= 5)
					setSpeedY(5);
				else
					setSpeedY(getSpeedY() + 1);
			case KEY_LEFT:
				if (getSpeedX() <= -5)
					setSpeedX(-5);
				else
					setSpeedX(getSpeedX() - 1);
			case KEY_RIGHT:
				if (getSpeedX() >= 5)
					setSpeedX(5);
				else
					setSpeedX(getSpeedX() + 1);
			case KEY_BACKSPACE:
				this->shoot();
		}
	}

	frame_advancementX = this->getFrameAdvanceX() + this->getSpeedX();
	frame_advancementY = this->getFrameAdvanceY() + this->getSpeedY();

	if (ABS(frame_advancementX) >= this->getFrameRate()) {
		this->setX(this->getX() + SIGNE(frame_advancementX));
	}
	if (ABS(frame_advancementY) >= this->getFrameRate()) {
		this->setY(this->getY() + SIGNE(frame_advancementY));
	}
	return;
}
