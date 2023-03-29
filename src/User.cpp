#include "User.h"
#include <cmath>
#include <random>

void User::updatePosition(float t){
    position = speed * t * 0.001; //temp - milisekundy?
}
UserStatus User::updateUser()
{
    updatePosition(time);
    if(position > X_DISTANCE) return Left_system;

    float powerFirstBTS = calculatePower(abs(position - BTS_POSITION[0]));
    float powerSecondBTS = calculatePower(abs(position - BTS_POSITION[1]));
    float diff = powerSecondBTS - powerFirstBTS;

    if(abs(diff) > DELTA) return Broken;

    //ifology to be changed
    if(diff >= ALPHA){
        if(alphaTimeout){
            alphaValue -= REPORT_TIME;
            if(alphaValue < = 0){
                currentBTS = 1;
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

float User::gauss(float mean, float dev){
    //temporary implementation
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::normal_distribution<float> d(mean, dev); 
    return d(gen);
}

float User::calculatePower(float d)
{
    return 4.56 - 22*log10(d) + gauss(0, 4);
}


User::User()
{
    //temp
    position = X_DISTANCE; /*switch to random*/
    alphaTimeout = false;
    alphaValue = TTT;
   
    btsPosition[0] = 0;
    btsPosition[1] = 1;

    currentBTS = 0;

    speed = 0;
    timeToReport = 0;
}