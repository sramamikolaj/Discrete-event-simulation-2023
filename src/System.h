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

    
    int usersInQueue; 
    std::list<User*> usersInSystem;
    
    User* addUser();
    void removeUser(User*);
public:
    System(); 

    void updateSystem();
    
};

#endif