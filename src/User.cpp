#include "User.h"
#include <cmath>
#include <random>
#include <iostream>

User::User(float speed_, Generator* random_, double tttMax_)
{
    tttMax          = tttMax_;
    position        = X_DISTANCE;
    tttOngoing      = false;
    timeToTrigger   = tttMax_;
    currentBTS      = 0;
    speed           = speed_;
    random          = random_;
}

UserStatus User::updateUser()
{
    updatePosition();
    if(position > BTS_POSITION[1]-X_DISTANCE) return LEFT_SYSTEM;
    
    float powerCurrentBTS = calculatePower(abs(position - BTS_POSITION[currentBTS]));
    float powerSecondBTS  = calculatePower(abs(position - BTS_POSITION[!currentBTS]));
    float powerDifference = powerCurrentBTS - powerSecondBTS;

    if((-1)*powerDifference > DELTA){
    return CONNECTION_BROKEN;
    }
    if((-1)*powerDifference > ALPHA){
        if(tttOngoing){
            timeToTrigger -= REPORT_TIME;
            if(timeToTrigger <= 0){
                currentBTS    = !currentBTS;
                timeToTrigger = tttMax;
                tttOngoing    = false;
                return BTS_SWITCHED;
            }
        }
        else tttOngoing = true;
    }
    else if(tttOngoing){
        tttOngoing = false;
        timeToTrigger = tttMax;
    }

    return NO_NEWS;
}

void User::updatePosition()
{
    position += speed * REPORT_TIME;
}

float User::calculatePower(float d)
{
    return 4.56 - 22*log10(d) + random->generateGaussian(0, 4);
}

