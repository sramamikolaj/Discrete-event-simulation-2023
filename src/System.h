#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h" 
#include<queue>
#include<list>
#include<map>
#include<string>

class System{
public:
    float BTSposition[2];

    std::queue<User> userQueue; 
    std::list<User> usersInSystem;
    
    void addUser();

public:
    System(); 

    void updateSystem();
    
};

#endif