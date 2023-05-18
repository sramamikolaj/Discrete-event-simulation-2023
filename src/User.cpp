#include "User.h"
#include <cmath>
#include <random>
#include <iostream>

void User::updatePosition(){
    position += speed * REPORT_TIME * 0.001;
}
UserStatus User::updateUser()
{
    updatePosition();
    if(position > BTS_POSITION[1]) return Left_system;

    float powerFirstBTS     = calculatePower(abs(position - BTS_POSITION[0]));
    float powerSecondBTS    = calculatePower(abs(position - BTS_POSITION[1]));
    float diff = powerSecondBTS - powerFirstBTS;

    if(abs(diff) > DELTA){
        //std::cout << "  User broken on " << position << " (with speed " << speed << ")" << std::endl;
        return Broken;
    }

    //ifology to be changed
    if(diff >= ALPHA && currentBTS == 0){
        if(alphaTimeout){
            alphaValue -= REPORT_TIME;
            if(alphaValue <= 0){
                currentBTS = 1;
                alphaValue = TTT;
                alphaTimeout = false;
                return BTS_switched;
            } 
        }
        else{
            alphaTimeout = true;
        }
    }
    else if(alphaTimeout){
        alphaTimeout = false;
        alphaValue = TTT;
    }

    return Good;
}

float User::calculatePower(float d)
{
    return 4.56 - 22*log10(d) + random->generateGaussian(0, 4);
}

User::User(float speed_, Generator* random_)
{
    position    = X_DISTANCE;
    alphaTimeout= false;
    alphaValue  = TTT;
    currentBTS  = 0;
    speed       = speed_;
    random      = random_;
}