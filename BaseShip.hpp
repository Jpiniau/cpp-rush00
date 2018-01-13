/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:27:17 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 16:26:45 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASESHIP_HPP
# define BASESHIP_HPP

#include "ISpaceShip.hpp"
#include "IPlayer.hpp"
#include "Projectile.hpp"
#include <ncurses.h>

class BaseShip : public ISpaceShip, public IPlayer
{
	public :
		BaseShip(void);
		BaseShip(BaseShip const & src);
		~BaseShip(void);
		
		void	shoot(void);
		int *	detectInput(void);
		void	setCoord(void);
};

#endif
