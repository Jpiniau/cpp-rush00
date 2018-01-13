/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:21:53 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 15:05:38 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IEnemy_HPP
# define IEnemy_HPP

class IEnemy
{
	public :
		virtual	IEnemy(void);
		virtual	~IEnemy(void);

		virtual void	patern(void) const = 0;
		virtual void	setRandSpeed(void) const = 0;
		virtual void	setRandCoord(void) const = 0;
}

#endif
