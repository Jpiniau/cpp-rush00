/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:03:54 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 19:55:15 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASpaceShip_HPP
# define ASpaceShip_HPP

class ASpaceShip
{
	public :
		ASpaceShip(void);
		ASpaceShip(ASpaceShip const &src);
		virtual ~ASpaceShip(void) = 0;

		virtual void	shoot(void) = 0;
		ASpaceShip const & operator=(ASpaceShip const & rhs);
};

#endif
