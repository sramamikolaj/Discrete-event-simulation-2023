#include "System.h"
#include<iostream>
System::System()
{
    std::cout << "System constructor" << std::endl;
    usersInQueue = 0;
    random = new Generator(394613);
    usersRandom = new Generator(883927);
}
void System::removeUser(User* user){
    usersInSystem.remove(user);
    delete user;
}

void System::updateSystem()
{
    delete random;
    delete usersRandom;
}

User* System::addUser(){
    if(usersInSystem.size() >= USER_LIMIT){
        std::cout << "  User not added" << std::endl;
        return nullptr; 
    }
    usersInSystem.push_back(new User(random->rand(), usersRandom));
    std::cout << "  User added" << std::endl;
    return usersInSystem.back();
}