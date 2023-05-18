#ifndef EXECUTIONFLAGS_H
#define EXECUTIONFLAGS_H
#include "User.h"

struct ExecutionFlags{
    ExecutionFlags(){
        userLeft = false;
        userBrokeConnection = false;
        systemFull = false;
        user = nullptr;
        userSwitched = 0;
    }
    bool anyFlag(){
        if(userLeft || userBrokeConnection || systemFull || userSwitched) return true;
        return false;
    }
    
    bool userLeft;
    bool userBrokeConnection;
    bool systemFull;
    bool userSwitched;

    User* user;  
};

#endif 