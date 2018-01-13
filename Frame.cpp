/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Frame.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:36:59 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 20:28:34 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Frame.hpp" 

Frame::Frame(void) {
    return;
}

Frame::Frame(Frame const & src) {
    *this = src;
}

Frame::~Frame(void) {
    return;
}

Frame &         Frame::operator=(Frame const & rhs) {
    this->setPtr(rhs.getPtr());
    return (*this);
}

void            Frame::generateFrame(void) {

}

void            Frame::spawnRandomEnemy(void) {
    AEntity     *ptr;
    srand(time(NULL));
    static int salt = rand() + 7;
    int     val = ((rand() + salt++) % 2);
    if (val < 0 || val > 1)
        val = 0;
    switch (val) {
        case 0:
            ptr = new Meteor();
        break;
        case 1:
            ptr = new Mine();
        break;
    }
    
}

void            Frame::updateAll(void) {
    
}

//getteurs
AEntity const & Frame::getPtr(void) const {    return (*(this->_ptr));}

//setteurs
void            Frame::setPtr(AEntity const & entity) {
    *(this->_ptr) = entity;
}