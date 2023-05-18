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
    float   calculatePower(float);

public:
    User(float speed_, Generator* random_);
    UserStatus  updateUser();

};

#endif


