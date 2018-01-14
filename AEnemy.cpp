/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:48:35 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 12:54:50 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEnemy.hpp"

AEnemy::AEnemy(void) {
    return;
}

AEnemy::AEnemy(AEnemy const & src) {
    *this = src;
    return;
}

AEnemy::~AEnemy(void) {
}

	AEnemy const &AEnemy::operator=(AEnemy const &rhs) {
    return (rhs);
}
