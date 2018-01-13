/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:48:35 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 18:50:41 by vnoon            ###   ########.fr       */
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

AEnemy const &AEnemy::operator=(AEnemy const &rhs) {
    return (rhs);
}