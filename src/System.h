#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include "Generator.h" 
#include<queue>
#include<list>
#include<map>
#include<string>
#include<vector>

class System{
public:
    Generator*       usersRandom;
    Generator*       random;
    int              usersInQueue; 
    std::list<User*> usersInSystem;
    double tttMax;
    
    User*   addUser();
    void    removeUser(User*);
public:
    System(double tttMax_, std::vector<int>& seeds); 
    ~System();
    
};

#endif