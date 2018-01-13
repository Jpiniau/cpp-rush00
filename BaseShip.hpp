/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:27:17 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 18:34:09 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASESHIP_HPP
# define BASESHIP_HPP

#include "ISpaceShip.hpp"
#include "IPlayer.hpp"
#include "Projectile.hpp"
#include <ncurses.h>
#include <cstddef>

class BaseShip : public ISpaceShip, public IPlayer, public AEntity
{
	public :
		BaseShip(void);
		BaseShip(BaseShip const & src);
		~BaseShip(void);
		
		void	shoot(void);
		void	detectInput(void);
		void	setCoord(void);
		void	move(void);

		void	setCH(int *ch, int len);
		int		*getCH(void);

		BaseShip &	operator=(BaseShip const & rhs);

	private:
		int		_ch[4];
};

#endif
