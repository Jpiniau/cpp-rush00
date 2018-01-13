/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:03:54 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 16:06:21 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACESHIP_HPP
# define ISPACESHIP_HPP

class ISpaceShip
{
	public :
		ISpaceShip(void) const = 0;
		virtual ~ISpaceShip(void) const = 0;

		virtual void	shoot(void) const = 0;
};

#endif
