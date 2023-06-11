#ifndef EXECUTIONINFO_H
#define EXECUTIONINFO_H
#include "User.h"

struct ExecutionInfo{
    ExecutionInfo(){
        userLeft            = false;
        userBrokeConnection = false;
        systemFull          = false;
        userRequestsSwitch  = false;
        user                = nullptr;
    }
    bool anyFlag(){
        if(userLeft || userBrokeConnection || systemFull || userRequestsSwitch) return true;
        return false;
    }
    
    bool userLeft;
    bool userBrokeConnection;
    bool systemFull;
    bool userRequestsSwitch;
    User* user;  
};

#endif 