#ifndef USER_H
#define USER_H

#include"defs.h"
#include "Generator.h"


class User
{
    float   alphaValue;
    short   currentBTS;
    bool    alphaTimeout;
    float   position;
    float   speed;

    Generator * random;
    void    updatePosition();
    float   gauss(float mean, float dev);
    float   calculatePower(float);
    float   getRandom();

public:
    User(float speed_, Generator* random_);
    UserStatus  updateUser();

    
    
};

#endif


