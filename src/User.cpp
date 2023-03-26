#include "User.h"
#include<cmath>


UserStatus User::updateUser()
{

    float powerFirstBTS = calculatePower(abs(position - btsPosition[0]));
    float powerSecondBTS = calculatePower(abs(position - btsPosition[1]));
    float diff = powerFirstBTS - powerSecondBTS;

    

    return Good;
}

float User::calculatePower(float d)
{
    float gauss = 0; //switch to normal distr
    return 4.56 - 22*log10(d) + gauss;
}

void User::generateRandom()
{
    speed = 0;
    timeToReport = 0;
}

User::User()
{

    position = 0; /*switch to random*/
    alphaTimeout = false;

    //temp
    btsPosition[0] = 0;
    btsPosition[1] = 1;

    currentBTS = 0;

    generateRandom();
}