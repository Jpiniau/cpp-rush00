/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:55:58 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/14 16:32:00 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <string>
//#include "Frame.hpp"

class   AEntity {
    private:
	std::string			_appearance;
    int                 _x;
    int                 _y;
    int                 _speedX;
    int                 _speedY;
    int                 _frameAdvanceX;
    int                 _frameAdvanceY;
    int                 _hp;
    int                 _armor;
    int                 _allegiance;
    bool                _isJustDestroyed;
    AEntity             *_next;
    AEntity             *_prev;
    int		            _ch[4];

    protected:
    #define ABS(val) (val < 0 ? -val : val) 
   #define SIGNE(val)  (val < 0 ? -1 : 1) 
    #define FRAME_RATE 5

    AEntity(void);
    AEntity(AEntity const &src);
    AEntity(std::string appearance, int x, int y, int speedX, int speedY, 
            int frameAdvanceX, int frameAdvanceY, int hp, int armor,
            int allegiance, bool isJustDestroyed);
    ~AEntity(void);

    public:

    AEntity &       operator=(AEntity const &rhs);
    void            colideWith(void);

    virtual void    colisionEffect(AEntity ** entity) = 0;
    virtual void    move(void) = 0;
    virtual AEntity *factory(void) = 0;

    //getteurs
	std::string     getAppearance(void) const;
    int             getX(void) const;
    int             getY(void) const;
    int             getSpeedX(void) const;
    int             getSpeedY(void) const;
    int             getFrameAdvanceX(void) const;
    int             getFrameAdvanceY(void) const;
    int             getHP(void) const;
    int             getArmor(void) const;
    int             getAllegiance(void) const;
    int             getFrameRate(void) const;
    bool            getIsJustDestroyed(void) const;
    AEntity         *getNext(void) const;
    AEntity         *getPrev(void) const;
	int		        *getCH(void);
    //setteurs
    void            setAppearance(std::string const symbol);
    void            setX(int const value);
    void            setY(int const value);
    void            setSpeedX(int const value);
    void            setSpeedY(int const value);
    void            setFrameAdvanceX(int const value);
    void            setFrameAdvanceY(int const value);
    void            setHP(int const value);
    void            setArmor(int const value);
    void            setAllegiance(int const value);
    void            setIsJustDestroyed(bool const value);
    void            setNext(AEntity *next);
    void            setPrev(AEntity *prev);
    void        	setCH(int *ch, int len);
};

#endif
