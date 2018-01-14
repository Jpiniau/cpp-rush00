/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:15:56 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 19:50:34 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYSHIP
# define ENEMYSHIP

#include "AEntity.hpp"
#include "AEnemy.hpp"
#include "ASpaceShip.hpp"
#include "Projectile.hpp"

class EnemyShip : public AEntity, public AEnemy, public ASpaceShip {
	public :
		EnemyShip(void);//
		EnemyShip(EnemyShip const & src);//
		~EnemyShip(void);//
		
		void	shoot(void);//
		void	move(void);//

		EnemyShip &	operator=(EnemyShip const & rhs);//
		void		colisionEffect(AEntity ** entity);//

		EnemyShip	*factory(void);//
		void		destructor(void);//
        void	    patern(void);//
		void	    setRandSpeed(void);//
		void	    setRandCoord(void);//

        int         getCanonCharge(void);
        int         getCanonChargeLevel(void);

        void        setCanonCharge(int val);
        void        setCanonChargeLevel(int val);

	private:
        int         _canonCharge;
        int         _canonChargeLevel;
};

#endif