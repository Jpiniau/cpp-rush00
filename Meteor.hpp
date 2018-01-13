/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Meteor.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:09:00 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 15:38:37 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METEOR_HPP
# define METEOR_HPP

#include "IEnemy.hpp"
#include "AEntity.hpp"

class Meteor : public AEntity, public IEnemy {
    private:
    public:
    Meteor(void);
    Meteor(Meteor & const src);
    ~Meteor(void);

    Meteor &    operator=(Meteor & const rhs);

    void            colisionEffect(AEntity & const entity);
    void            move(void);
    void            patern(void);
    void            setRandSpeed(void);
    void            setRandCoord(void);

};

#endif