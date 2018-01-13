/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iplayer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:08:06 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 13:23:42 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPLAYER_HPP
# define IPLAYER_HPP

class IPlayer
{
	public :
		virtual int*	detectInput(void) const = 0;
		virtual void	setCoord(void) const = 0;

	private :
		virtual	IPlayer(void);
		virtual	~IPlayer(void);
}

#endif
