/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:08:54 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 14:26:22 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "AEntity.hpp"

class Projecile
{
	public :
		Projectile(void);
		Projectile(Projectile & const src);
		Projectile(int damage, int range);
		~Projectile(void);

		Projectile &	operator=(Projectile & const rhs);
		int				getDamage(void);
		int				getRange(void);
		int				setDamage(int value);
		int				setRange(int value);

	private :
		int	_damage;
		int	_range;
};

#endif
