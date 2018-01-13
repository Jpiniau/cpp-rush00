/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mine.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:25:53 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 15:11:48 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Mine.hpp"

Mine::Mine(void) : AEntity('@', 45, 45, 2, 2, 0, 0, 50, 2, 2, false), IEnemy() {
    return;
}

Mine::Mine(Mine & const src) : AEntity(src), IEnemy(src) {
    *this = src;
}

Mine::~Mine(void) {
    AEntity::~AEntity();
    IEnemy::~IEnemy();
}

Mine &          Mine::operator=(Mine & const rhs) {
    AEntity::operator=(rhs);
    return (*this);
}

void            Mine::colisionEffect(AEntity & const entity) {
    return;
}

void            Mine::move(void) {
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
    ptr = this->getNext();
    this->setNext(new Mine());
}