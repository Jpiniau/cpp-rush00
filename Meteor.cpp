/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Meteor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:12:28 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 16:07:59 by vnoon            ###   ########.fr       */
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