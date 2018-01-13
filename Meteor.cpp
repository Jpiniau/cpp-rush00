/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Meteor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:12:28 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 17:37:08 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Meteor.hpp"

Meteor::Meteor(void) : AEntity('#', 45, 45, 2, 2, 0, 0, 50, 2, 2, false), IEnemy() {
    return;
}

Meteor::Meteor(Meteor const & src) : AEntity(src), IEnemy(src) {
    *this = src;
}

Meteor::~Meteor(void) {
    AEntity::~AEntity();
    IEnemy::~IEnemy();
}

void            Meteor::colisionEffect(AEntity const & entity) {
    return;
}

void            Meteor::move(void) {
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

void            Meteor::patern(void) {
    return;
}

void            Meteor::setRandSpeed(void) {
    return;
}

void            Meteor::setRandCoord(void) {
    return;
}

Meteor &        Meteor::operator=(Meteor const & rhs) {
    AEntity::operator=(rhs);
    return (*this);
}