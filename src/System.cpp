#include "System.h"
#include<iostream>
System::System()
{
    std::cout << "System constructor" << std::endl;
    usersInQueue = 0;
}

void System::updateSystem()
{
    
}

User* System::addUser(){
    if(usersInSystem.size() >= USER_LIMIT){
        std::cout << "  User not added" << std::endl;
        return nullptr; 
    }
    usersInSystem.push_back(new User());
    std::cout << "  User added" << std::endl;
    return usersInSystem.back();
}