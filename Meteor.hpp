/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Meteor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:09:00 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 12:49:10 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METEOR_HPP
# define METEOR_HPP

#include "AEnemy.hpp"
#include "AEntity.hpp"

class Meteor : public AEntity, public AEnemy {
    private:
    public:
    Meteor(void);
    Meteor(int x, int y);
    Meteor(Meteor const & src);
    ~Meteor(void);

    Meteor &        operator=(Meteor const & rhs);

    void            colisionEffect(AEntity ** entity);
    void            move(void);
    void            patern(void);
    void            setRandSpeed(void);
    void            setRandCoord(void);

    Meteor          *factory(void);

};

#endif
