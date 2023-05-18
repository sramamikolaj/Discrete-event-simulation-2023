#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include "Generator.h" 
#include<queue>
#include<list>
#include<map>
#include<string>

class System{
public:
    float BTSposition[2];

    Generator* usersRandom;
    Generator* random;
    int usersInQueue; 
    std::list<User*> usersInSystem;
    
    User* addUser();
    void removeUser(User*);
public:
    System(); 
    ~System();
    
};

#endif