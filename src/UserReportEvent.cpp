#include "UserReportEvent.h"
#include <iostream>

ExecutionFlags UserReportEvent::execute(){
    ExecutionFlags returnInfo; 
    UserStatus status = user->updateUser();
    switch(status){
        case NO_NEWS:
            eq->push(new UserReportEvent(eventTime+REPORT_TIME, user, eq));
            break;
        case BTS_SWITCHED:
            returnInfo.userSwitched = true;    
            eq->push(new UserReportEvent(eventTime+REPORT_TIME, user, eq));
            break;
        case CONNECTION_BROKEN:
            returnInfo.userBrokeConnection = true;
            returnInfo.user = user;
            break;
        case LEFT_SYSTEM:
            returnInfo.userLeft = true;
            returnInfo.user = user;
            break;
    }
    return returnInfo;  
}
