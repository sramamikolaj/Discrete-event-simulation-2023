#ifndef USER_H
#define USER_H

#include "defs.h"
#include "Generator.h"
#include <cmath>

class User
{
    float   timeToTrigger; 
    float   tttMax; 
    bool    tttOngoing;
    short   currentBTS;
    float   position;
    float   speed;
    Generator* random;

    void    updatePosition();
    float   calculatePower(float);
    
public:
    User(float speed_, Generator* random_, float tttMax_);

    UserStatus  updateUser();
    void        switchBTS();
    float       getPosition();
    short       getBTS();
};

#endif


