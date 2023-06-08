#include "System.h"
#include<iostream>
System::System(double tttMax_, std::vector<int>& seeds)
{
    tttMax = tttMax_;
    usersInQueue = 0;
    randomSpeed = new Generator(seeds[1]);
    randomPower = new Generator(seeds[2]);
}
void System::removeUser(User* user){
    usersInSystem.remove(user);
    delete user;
}
System::~System()
{
    delete randomSpeed;
    delete randomPower;
}

User* System::addUser(){
    if(usersInSystem.size() >= USER_LIMIT){
        return nullptr; 
    }
    usersInSystem.push_back(new User(randomSpeed->rand(5, 50), randomPower, tttMax));
    return usersInSystem.back();
}