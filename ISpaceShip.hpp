/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:03:54 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 16:56:16 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACESHIP_HPP
# define ISPACESHIP_HPP

class ISpaceShip
{
	public :
		ISpaceShip(void);
		ISpaceShip(ISpaceShip const &src);
		virtual ~ISpaceShip(void) = 0;

		virtual void	shoot(void) = 0;
		virtual ISpaceShip & operator=(ISpaceShip const & rhs) = 0;
};

#endif
