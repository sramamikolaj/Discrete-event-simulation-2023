#include "System.h"
#include<iostream>
System::System(double tttMax_, std::vector<int>& seeds)
{
    tttMax = tttMax_;
    usersInQueue = 0;
    random = new Generator(seeds[1]);
    usersRandom = new Generator(seeds[2]);
}
void System::removeUser(User* user){
    usersInSystem.remove(user);
    delete user;
}
System::~System()
{
    delete random;
    delete usersRandom;
}

User* System::addUser(){
    if(usersInSystem.size() >= USER_LIMIT){
        return nullptr; 
    }
    usersInSystem.push_back(new User(random->rand(5, 50), usersRandom, tttMax));
    return usersInSystem.back();
}