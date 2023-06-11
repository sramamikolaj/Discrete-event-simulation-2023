#include "System.h"

System::System(double tttMax_, std::vector<int>& seeds)
{
    tttMax = tttMax_;
    usersInQueue = 0;
    randomSpeed = new Generator(seeds[1]);
    randomPower = new Generator(seeds[2]);
}

System::~System()
{
    delete randomSpeed;
    delete randomPower;
}

void System::removeUser(User* user){
    usersInSystem.remove(user);
    delete user;
}

void System::switchBTS(User* user)
{
    user->switchBTS();
}

User *System::addUser()
{
    if(usersInSystem.size() >= SYSTEM_CAPACITY) 
        return nullptr; 
    usersInSystem.push_back(new User(randomSpeed->rand(MIN_SPEED, MAX_SPEED), randomPower, tttMax));
    return usersInSystem.back();
}