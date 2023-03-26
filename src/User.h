#ifndef USER_H
#define USER_H

enum UserStatus
{
    Good = 0,
    Remove
};

class User
{

    short currentBTS;
    bool alphaTimeout;
    float btsPosition[2];
    float position;
    // Random::
    float timeToReport; /*t*/
    float speed;
    //////

    UserStatus updateUser();
    float calculatePower(float);

    void generateRandom();

public:
    User();
};

#endif