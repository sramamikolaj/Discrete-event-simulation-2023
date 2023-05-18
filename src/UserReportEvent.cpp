#include "UserReportEvent.h"
#include <iostream>

ExecutionFlags UserReportEvent::execute(){
    ExecutionFlags returnFlags; 
       

    UserStatus status = user->updateUser();
    if(status == BTS_switched){
        returnFlags.userSwitched = true;    
        eq->push(new UserReportEvent(eventTime+REPORT_TIME*0.001, user, eq));
        return returnFlags;
    }
    if(status != Broken && status != Left_system) 
        eq->push(new UserReportEvent(eventTime+REPORT_TIME*0.001, user, eq));
    else{
        returnFlags.user = user;
        switch(status){
            case Broken:
                returnFlags.userBrokeConnection = true;
                break;
            case Left_system:
                returnFlags.userLeft = true;
                break;
            case BTS_switched:
                
                break;
        }

    }
    
    return returnFlags;   
}
