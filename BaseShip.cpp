/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:50 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 17:58:04 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseShip.hpp"

BaseShip::BaseShip(void) : ISpaceShip(), IPlayer()
{
	return;
}

BaseShip::BaseShip(BaseShip const & src) : ISpaceShip(src), IPlayer(src)
{
	*this = src;
}

BaseShip::~BaseShip(void)
{
	return;
}

void	BaseShip::shoot(void)
{
	Projectile	*proj;
	AEntity		*list;

	list = this;
	while (list->getNext())
		list = list->getNext();

	proj = new Projectile('-', this->getX() + 1, this->getY(), 5, 0, 0, 0, 0, 0, 0, 0, 10, 20);

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
				setSpeedY(getSpeedY() - 1);
			case KEY_DOWN:
				setSpeedY(getSpeedY() + 1);
			case KEY_LEFT:
				setSpeedX(getSpeedX() - 1);
			case KEY_RIGHT: 
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
