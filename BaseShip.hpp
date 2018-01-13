/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseShip.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:27:17 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 15:00:00 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASESHIP_HPP
# define BASESHIP_HPP

#include <ncurses.h>

class BaseShip : public ISpaceShip, public IPlayer
{
	public :
		BaseShip(void);
		BaseShip(BaseShip & const src);
		~BaseShip(void);
		
		void	shoot(void);
		int		*detectinput(void);
		void	setCoord(void);
};

#endif
