/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:23:29 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 16:53:44 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"

Projectile::Projectile(void) : AEntity()
{
    return;
}

Projectile::Projectile(Projectile const & src) : AEntity(src)
{
    *this = src;
}

Projectile::Projectile(char appearence, int x, int y, int speedX, int speedY,
					   int frameAdvanceX, int frameAdvanceY, int hp, int armor,
					   int allegiance, bool isJustDestroyed, int damage, int range) :
                       AEntity(appearence, x, y, speedX, speedY, frameAdvanceX, frameAdvanceY,
                       hp, armor, allegiance, isJustDestroyed), _damage(damage), _range(range)
{
    return;
}

Projectile::~Projectile(void)
{
    return;
}

Projectile &Projectile::operator=(Projectile const & rhs)
{
    AEntity::operator=(rhs);
    this->setDamage(rhs.getDamage());
    this->setRange(rhs.getRange());
    return (*this);
}

void            Projectile::colisionEffect(AEntity const & entity) {
    return;
}

void            Projectile::move(void) {
    return;
}

int Projectile::getDamage(void) const
{
	return (this->_damage);
}

int Projectile::getRange(void) const
{
	return (this->_range);
}

void Projectile::setDamage(int const value)
{
    this->_damage = value;
}

void Projectile::setRange(int const value)
{
    this->_range = value;
}
