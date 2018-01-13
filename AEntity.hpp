/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnoon <vnoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:55:58 by vnoon             #+#    #+#             */
/*   Updated: 2018/01/13 13:26:13 by vnoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

class   AEntity {
    private:
    char                _appearance;
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

    AEntity(void);

    protected:
    static const int    _frameRate;

    public:
    AEntity(AEntity & const src);
    AEntity(char appearance, int x, int y, int speedX, int speedY, 
            int frameAdvanceX, int frameAdvanceY, int hp, int armor,
            int allegiance, bool isJustDestroyed);
    ~AEntity(void);

    AEntity &       operator=(AEntity & const rhs);
    AEntity         *colideWith(void);
    virtual void    colisionEffect(AEntity & const entity) = 0;
    virtual void    move(void) = 0;


    //getteurs
    char            getAppearance(void) const;
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

    //setteurs
    void            setAppearance(char symbol);
    void            setX(int value);
    void            setY(int value);
    void            setSpeedX(int value);
    void            setSpeedY(int value);
    void            setFrameAdvanceX(int value);
    void            setFrameAdvanceY(int value);
    void            setHP(int value);
    void            setArmor(int value);
    void            setAllegiance(int value);
    void            setIsJustDestroyed(bool value);

};

#endif