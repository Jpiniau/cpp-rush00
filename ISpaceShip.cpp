/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:10:24 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 18:53:46 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceShip.hpp"

ISpaceShip::ISpaceShip(void) {
    return;
}

ISpaceShip::ISpaceShip(ISpaceShip const & src) {
    *this = src;
    return;
}
