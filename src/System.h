#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h" 
#include<queue>
#include<list>
#include<map>
#include<string>

class System{
    float BTSposition[2];

    std::queue<User> userQueue; 
    std::list<User> usersInSystem;
    
    //std::map<std::string, float> constants;
    //bool readConstants;

    void addUser();

public:
    System(); 

    void updateSystem();
    
};

#endif