/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:27:17 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/14 14:04:57 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASESHIP_HPP
# define BASESHIP_HPP

#include "ASpaceShip.hpp"
#include "APlayer.hpp"
#include "AEntity.hpp"
#include "Projectile.hpp"
#include <ncurses.h>
#include <cstddef>

class BaseShip : public ASpaceShip, public APlayer, public AEntity
{
	public :
		BaseShip(void);
		BaseShip(BaseShip const & src);
		~BaseShip(void);
		
		void	shoot(void);
		void	detectInput(void);
		void	setCoord(void);
		void	move(void);

		BaseShip &	operator=(BaseShip const & rhs);
		void		colisionEffect(AEntity ** entity);

		BaseShip	*factory(void);

	private:
};

#endif
