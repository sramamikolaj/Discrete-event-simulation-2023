#include "System.h"
#include<iostream>
System::System()
{
    usersInQueue = 0;
    random = new Generator(394613);
    usersRandom = new Generator(883927);
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
    usersInSystem.push_back(new User(random->rand(5, 50), usersRandom));
    return usersInSystem.back();
}