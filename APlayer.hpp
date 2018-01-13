/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APlayer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:08:06 by jpiniau           #+#    #+#             */
/*   Updated: 2018/01/13 19:55:53 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APlayer_HPP
# define APlayer_HPP

class APlayer
{
	public :
		APlayer(void);
		APlayer(APlayer const & src);
		virtual	~APlayer(void) = 0;

		virtual void	detectInput(void) = 0;
		virtual void	setCoord(void) = 0;

		APlayer const &	operator=(APlayer const & rhs);

};

#endif
