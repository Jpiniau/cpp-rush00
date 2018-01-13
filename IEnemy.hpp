/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:21:53 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 16:20:36 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IEnemy_HPP
# define IEnemy_HPP

class IEnemy
{
	public :
		IEnemy(void);
		IEnemy(IEnemy const & src);
		virtual	~IEnemy(void) = 0;

		virtual void	patern(void) = 0;
		virtual void	setRandSpeed(void) = 0;
		virtual void	setRandCoord(void) = 0;

		virtual IEnemy & operator=(IEnemy const & rhs) = 0;
};

#endif
