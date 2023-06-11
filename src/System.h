#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include "Generator.h" 
#include <list>
#include <vector>

class System{
    Generator*       randomPower;
    Generator*       randomSpeed;
    double           tttMax;

public:
    System(double tttMax_, std::vector<int>& seeds); 
    ~System();
    
    int              usersInQueue; 
    std::list<User*> usersInSystem;

    void    switchBTS(User*);
    User*   addUser();
    void    removeUser(User*);
};

#endif