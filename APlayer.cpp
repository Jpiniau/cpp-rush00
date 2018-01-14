/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APlayer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:10:38 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/14 12:57:01 by jpiniau          ###   ########.fr       */
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

APlayer::~APlayer(void) {
}

APlayer const &  APlayer::operator=(APlayer const & rhs) {
    return (rhs);
}
