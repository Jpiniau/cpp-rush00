/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:50 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 15:51:34 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseShip.hpp"

BaseShip::BaseShip(void) : ISpaceShip(void), IPlayer(void)
{
    return;
}

BaseShip::BaseShip(BaseShip &const src) : ISpaceShip(src), IPlayer(src)
{
    *this = src;
}

BaseShip::~BaseShip(void)
{
    return;
}

void	BaseShip::shoot(void)
{
	Projectile	proj;
	AEntity		list;

	list = this;
	while (list->next)
		list = getNext();

	proj = new Projectile("-", this->x + 1, this->y, 3, 0, 0, 0, 0, 0, 0, 0, 10, 20);
	
	list.setNext(proj);
	proj.setPrev(list);
	proj.setNext(NULL)
	return;
}

int *	BaseShip::detectInput(void)
{
	int		ch[4];
	int		i;

	i = -1;
	while (++i < 4)
	{
		ch[i] = getch();
	}
	return (ch);
}

void	BaseShip::SetCoord(void)
{
	this->setX(5);
	this->setY(5);
	return;
}

BaseShip &	BaseShip::operator=(BaseShip & const rhs)
{
	Aentity::operator=(rhs);
	return (*this);
}
