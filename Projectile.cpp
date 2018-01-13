/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:23:29 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 14:50:09 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : AEntity(void)
{
    return;
}

Projectile::Projectile(Projectile &const src) : Aentity(src)
{
    *this = src;
}

Projectile::Projectile(char appearence, int x, int y, int speedX, int speedY,
					   int frameAdvanceX, int frameAdvanceY, int hp, int armor,
					   int allegiance, bool isJustDestroyed, int damage, int range) :
					   _appearance(appearence), _x(x), _y(y), _speedX(speedX), _speedY(speedY),
					   _frameAdvanceX(frameAdvanceX), _frameAdvanceX(frameAdvanceX), _hp(hp),
					   _armor(armor), _allegiance(qllegiance), _isJustDestroyed(isJustDestroyed)
{
	this->_damage = damage;
	this->range = range;
    return;
}

Projectile::~Projectile(void)
{
    return;
}

Projectile &Projectile::operator=(Projectile &const rhs)
{
    this->setDamage(rhs.getDamage());
    this->setRange(rhs.getRange());
    return (*this);
}

int Projectile::getDamage(void) const
{
	return (this->_damage);
}

int Projectile::getRange(void) const
{
	return (this->_Range);
}

void Projectile::setDamage(int const value)
{
    this->_damage = value;
}

void Projectile::setRange(int const value)
{
    this->_range = value;
}
