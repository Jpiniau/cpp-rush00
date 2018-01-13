/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:33:50 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 15:04:53 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseShip.hpp"

BaseShip::BaseShip(void) :
{
    return;
}

BaseShip::BaseShip(BaseShip &const src) :
{
    *this = src;
}

BaseShip::~BaseShip(void)
{
    return;
}

void	BaseShip::shoot(void)
{
	new projectile("-", this->x + 1, this->y, 3, 0, 0, 0, 0, 0, 0, 0, 10, 20);
	return;
}

int		*BaseShip::detectInput(void)
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
