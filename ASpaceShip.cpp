/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:10:24 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 19:54:41 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpaceShip.hpp"

ASpaceShip::ASpaceShip(void) {
    return;
}

ASpaceShip::ASpaceShip(ASpaceShip const & src) {
    *this = src;
    return;
}

ASpaceShip const & ASpaceShip::operator=(ASpaceShip const & rhs) {
    return (rhs);
}
