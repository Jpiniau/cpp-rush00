/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mine.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:25:53 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 17:37:35 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Mine.hpp"

Mine::Mine(void) : AEntity('@', 45, 45, 2, 2, 0, 0, 50, 2, 2, false), IEnemy() {
    return;
}

Mine::Mine(Mine const & src) : AEntity(src), IEnemy(src)  {
    *this = src;
}

Mine::~Mine(void) {
    AEntity::~AEntity();
    IEnemy::~IEnemy();
}

Mine &          Mine::operator=(Mine const & rhs) {
    AEntity::operator=(rhs);
    return (*this);
}

void            Mine::colisionEffect(AEntity const & entity) {
    return;
}

void            Mine::move(void) {
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

void            Mine::patern(void) {
    return;
}

void            Mine::setRandSpeed(void) {
    return;
}

void            Mine::setRandCoord(void) {
    return;
}

void            Mine::spawnMeteor(void) {
    AEntity     *ptr;
//   ptr = new Mine();
    ptr = this->getNext();
//    this->setNext(*ptr);
}