#ifndef USER_H
#define USER_H

#include"defs.h"

class User
{
    void    updatePosition(float);
    float   alphaValue;
    short   currentBTS;
    bool    alphaTimeout;
    float   position;
    // Random::
    float   timeToReport; /*t*/
    float   speed;
    //////

    float   gauss(float mean, float dev);
    float   calculatePower(float);

public:
    User();
    UserStatus  updateUser();
};

#endif


