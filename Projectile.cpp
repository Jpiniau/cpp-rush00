/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:23:29 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 19:26:39 by vnoon            ###   ########.fr       */
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

void            Projectile::colisionEffect(AEntity ** entity) {
    AEntity *ptr;

    ptr = *entity;
/*  ptr->getNext()->setPrev(ptr->getPrev());
    ptr->getPrev()->setNext(ptr->getNext());
    delete entity;*/
    ptr->setHP(ptr->getHP() - CALC_DAMAGE(this->getDamage(), this->getArmor()));
    if (ptr->getHP() <= 0)
        ptr->setIsJustDestroyed(true);
    this->setIsJustDestroyed(true);
    return;
}

void            Projectile::move(void) {
    int frame_advancementX = this->getFrameAdvanceX() + this->getSpeedX();
    int frame_advancementY = this->getFrameAdvanceY() + this->getSpeedY();

    if (ABS(frame_advancementX) >= this->getFrameRate()) {
        this->setX(this->getX() + SIGNE(frame_advancementX));
    }
    if (ABS(frame_advancementY) >= this->getFrameRate()) {
        this->setY(this->getY() + SIGNE(frame_advancementY));
    }
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
