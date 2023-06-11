#include "UserReportEvent.h"
#include <iostream>

UserReportEvent::UserReportEvent(double time, User *user_, std::priority_queue<TimedEvent *, std::vector<TimedEvent *>, Compare> *eq_)
    :TimedEvent(time, eq_)
{
    user = user_;
}

ExecutionInfo UserReportEvent::execute()
{
    ExecutionInfo returnInfo; 
    returnInfo.user = user;
    UserStatus status = user->updateUser();
    switch(status){
        case NO_NEWS:
            eq->push(new UserReportEvent(eventTime+REPORT_TIME, user, eq));
            break;
        case BTS_SWITCH_REQUEST:
            returnInfo.userRequestsSwitch = true;    
            eq->push(new UserReportEvent(eventTime+REPORT_TIME, user, eq));
            break;
        case CONNECTION_BROKEN:
            returnInfo.userBrokeConnection = true;
            break;
        case LEFT_SYSTEM:
            returnInfo.userLeft = true;
            break;
    }
    return returnInfo;
}
