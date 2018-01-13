/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:50 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 18:10:02 by vnoon            ###   ########.fr       */
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

	proj = new Projectile('-', this->getX() + 1, this->getY(), 3, 0, 0, 0, 0, 0, 0, 0, 10, 20); //Projectile('-', this->getX() + 1, this->getY(), 3, 0, 0, 0, 0, 0, 0, 0, 10, 20);
	
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

int		 *BaseShip::getCH(void) {
	return ((this->_ch));
}