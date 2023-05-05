#ifndef USER_H
#define USER_H

#include"defs.h"



class User
{
    float   alphaValue;
    short   currentBTS;
    bool    alphaTimeout;
    float   position;
    float   speed;

    void    updatePosition();
    float   gauss(float mean, float dev);
    float   calculatePower(float);
    float   getRandom();

public:
    User();
    UserStatus  updateUser();

    
    
};

#endif


