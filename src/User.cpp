#include "User.h"
#include<cmath>
#include <random>

void User::updatePosition(float t){
    position = speed * t * 0.001; //temp - milisekundy?
}
UserStatus User::updateUser(float time)
{
    updatePosition(time);

    float powerFirstBTS = calculatePower(abs(position - btsPosition[0]));
    float powerSecondBTS = calculatePower(abs(position - btsPosition[1]));
    float diff = powerSecondBTS - powerFirstBTS;

    if(abs(diff) > DELTA) return Broken;

    if(diff >= alphaValue){
        if(alphaTimeout){
            
        }
        else{

        }
    }


    return Good;
}

float User::gauss(float mean, float dev){
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
    alphaValue = ALPHA;
   
    btsPosition[0] = 0;
    btsPosition[1] = 1;

    currentBTS = 0;

    speed = 0;
    timeToReport = 0;
}