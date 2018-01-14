/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:55:52 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 11:41:39 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"
#include <cstddef>

#define FRAME_RATE 5

AEntity::AEntity(void)
{
    return;
}

AEntity::AEntity(AEntity const &src)
{
    *this = src;
}

AEntity::AEntity(std::string appearance, int x, int y, int speedX, int speedY,
                 int frameAdvanceX, int frameAdvanceY, int hp, int armor,
                 int allegiance, bool isJustDestroyed) : _appearance(appearance),
                                                         _x(x), _y(y), _speedX(speedX), _speedY(speedY),
                                                         _frameAdvanceX(frameAdvanceX), _frameAdvanceY(frameAdvanceY), _hp(hp), _armor(armor),
                                                         _allegiance(allegiance), _isJustDestroyed(isJustDestroyed)
{
    return;
}

AEntity::~AEntity(void)
{
    return;
}

AEntity &AEntity::operator=(AEntity const &rhs)
{
    this->setAppearance(rhs.getAppearance());
    this->setX(rhs.getX());
    this->setY(rhs.getY());
    this->setSpeedX(rhs.getSpeedX());
    this->setSpeedY(rhs.getSpeedY());
    this->setFrameAdvanceX(rhs.getFrameAdvanceX());
    this->setFrameAdvanceY(rhs.getFrameAdvanceY());
    this->setHP(rhs.getHP());
    this->setArmor(rhs.getArmor());
    this->setAllegiance(rhs.getAllegiance());
    this->setIsJustDestroyed(rhs.getIsJustDestroyed());
    this->setNext(rhs.getNext());
    this->setPrev(rhs.getPrev());
    return (*this);
}

void     AEntity::colideWith(void) {
    AEntity     *ptrToOrgn = this;
    for (AEntity *ptr = this; ptr != NULL; ptr = ptr->getNext())
        for (AEntity *ptrNav = ptrToOrgn; ptrNav != NULL; ptrNav->getNext())
            if ((ptr != ptrNav) && (ptr->getX() == ptrNav->getX()) && (ptr->getY() == ptrNav->getY()))
                ptr->colisionEffect(&ptrNav);
}

//getteurs
std::string AEntity::getAppearance(void) const	{ return (this->_appearance); }
int AEntity::getX(void) const                   { return (this->_x); }
int AEntity::getY(void) const                   { return (this->_y); }
int AEntity::getSpeedX(void) const              { return (this->_speedX); }
int AEntity::getSpeedY(void) const              { return (this->_speedY); }
int AEntity::getFrameAdvanceX(void) const       { return (this->_frameAdvanceX); }
int AEntity::getFrameAdvanceY(void) const       { return (this->_frameAdvanceY); }
int AEntity::getHP(void) const                  { return (this->_hp); }
int AEntity::getArmor(void) const               { return (this->_armor); }
int AEntity::getAllegiance(void) const          { return (this->_allegiance); }
int AEntity::getFrameRate(void) const           { return (FRAME_RATE); }
bool AEntity::getIsJustDestroyed(void) const    { return (this->_isJustDestroyed); }
AEntity *AEntity::getNext(void) const           { return (this->_next);}
AEntity *AEntity::getPrev(void) const           { return (this->_prev);}

//setteurs
void AEntity::setAppearance(std::string const symbol)
{
    this->_appearance = symbol;
}

void AEntity::setX(int const value)
{
    this->_x = value;
}
void AEntity::setY(int const value)
{
    this->_y = value;
}
void AEntity::setSpeedX(int const value)
{
    this->_speedX = value;
}

void AEntity::setSpeedY(int const value)
{
    this->_speedY = value;
}

void AEntity::setFrameAdvanceX(int const value)
{
    this->_frameAdvanceX = value;
}
void AEntity::setFrameAdvanceY(int const value)
{
    this->_frameAdvanceY = value;
}

void AEntity::setHP(int const value)
{
    this->_hp = value;
}

void AEntity::setArmor(int const value)
{
    this->_armor = value;
}

void AEntity::setAllegiance(int const value)
{
    this->_allegiance = value;
}

void AEntity::setIsJustDestroyed(bool const value)
{
    this->_isJustDestroyed = value;
}

void AEntity::setNext(AEntity *next) {
    this->_next = next;
}
void AEntity::setPrev(AEntity *prev) {
    this->_prev = prev; 
}
