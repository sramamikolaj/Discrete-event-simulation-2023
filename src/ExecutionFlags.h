#ifndef EXECUTIONFLAGS_H
#define EXECUTIONFLAGS_H
#include "User.h"

struct ExecutionFlags{
    ExecutionFlags(){
        userLeft = false;
        userBrokeConnection = false;
        systemFull = false;
        user = nullptr;
    }
    bool anyFlag(){
        if(userLeft || userBrokeConnection || systemFull) return true;
        return false;
    }
    
    bool userLeft;
    bool userBrokeConnection;
    bool systemFull;

    User* user;  
};

#endif 