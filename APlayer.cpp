/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APlayer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:10:38 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 19:56:44 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "APlayer.hpp"

APlayer::APlayer(void) {
    return;
}

APlayer::APlayer(APlayer const & src) {
    *this = src;
    return;
}

APlayer const &  APlayer::operator=(APlayer const & rhs) {
    return (rhs);
}