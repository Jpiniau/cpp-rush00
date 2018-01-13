/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEnemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:21:53 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 18:50:53 by vnoon            ###   ########.fr       */
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
