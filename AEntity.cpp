/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:55:52 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 13:34:53 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

int const               _frameRate = 5;

AEntity::AEntity(void) {
    return;
}

AEntity::AEntity(AEntity & const src) {
    *this = src;
}

AEntity::AEntity(char appearance, int x, int y, int speedX, int speedY, 
            int frameAdvanceX, int frameAdvanceY, int hp, int armor,
            int allegiance, bool isJustDestroyed) : _appearance(appearance),
            _x (x), _y (y), _speedX (speedX), _speedY(speedY), 
            _frameAdvanceX (frameAdvanceX), _frameAdvanceY(frameAdvanceY), _hp (hp), _armor (armor),
            _allegiance (allegiance), _isJustDestroyed(isJustDestroyed) {
    return;
}

