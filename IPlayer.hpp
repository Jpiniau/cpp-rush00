/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPlayer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:08:06 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 16:25:23 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPLAYER_HPP
# define IPLAYER_HPP

class IPlayer
{
	public :
		IPlayer(void);
		IPlayer(IPlayer const & src);
		virtual	~IPlayer(void) = 0;

		virtual int*	detectInput(void) = 0;
		virtual void	setCoord(void) = 0;

		virtual IPlayer &	operator=(IPlayer const & rhs) = 0;

};

#endif
