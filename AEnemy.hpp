/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:24:36 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 20:26:00 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AEnemy_HPP
# define AEnemy_HPP

class AEnemy
{
	public :
		AEnemy(void);
		AEnemy(AEnemy const & src);
		virtual	~AEnemy(void) = 0;

		virtual void	patern(void) = 0;
		virtual void	setRandSpeed(void) = 0;
		virtual void	setRandCoord(void) = 0;

		AEnemy const & operator=(AEnemy const &rhs);
};

#endif
