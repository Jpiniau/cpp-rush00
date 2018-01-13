/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mine.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:25:50 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 14:57:26 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINE_HPP
# define MINE_HPP

#include "AEntity.hpp"
#include "IEnemy.hpp"

class Mine : public AEntity, public IEnemy {
    private:
    public:
    Mine(void);
    Mine(Mine & const src);
    ~Mine(void);

    Mine &    operator=(Mine & const rhs);
    void      spawnMeteor(void);      
};

#endif