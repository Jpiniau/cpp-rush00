/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:23:29 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/14 16:19:02 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile(void) : AEntity()
{
	return;
}

Projectile::Projectile(Projectile const & src) : AEntity(src)
{
	*this = src;
}

Projectile::Projectile(std::string appearence, int x, int y, int speedX, int speedY,
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

Projectile	*Projectile::factory(void) {
	Projectile *new_Projectile;

	new_Projectile = new Projectile();
	return (new_Projectile);
}

void            Projectile::move(void) {

	this->setFrameAdvanceX(this->getFrameAdvanceX() + this->getSpeedX());
	this->setFrameAdvanceY(this->getFrameAdvanceY() + this->getSpeedY());

	if (ABS(this->getFrameAdvanceX()) >= FRAME_RATE) {
		this->setX(this->getX() + (getFrameAdvanceX() % FRAME_RATE));
		this->setFrameAdvanceX(this->getFrameAdvanceX() % FRAME_RATE);
	}
	if (ABS(this->getFrameAdvanceY()) >= FRAME_RATE) {
		this->setY(this->getY() + (getFrameAdvanceY() % FRAME_RATE));
		this->setFrameAdvanceY(this->getFrameAdvanceY() % FRAME_RATE);
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
