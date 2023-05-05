#include "UserReportEvent.h"
#include <iostream>

ExecutionFlags UserReportEvent::execute(){
    ExecutionFlags returnFlags; 
       

    UserStatus status = user->updateUser();
    if(status != Broken && status != Left_system) 
        eq->push(new UserReportEvent(eventTime+2, user, eq));
    else{
        returnFlags.user = user;
        switch(status){
            case Broken:
                returnFlags.userBrokeConnection = true;
                break;
            case Left_system:
                returnFlags.userLeft = true;
                break;
        }

    }
    
    return returnFlags;   
}
