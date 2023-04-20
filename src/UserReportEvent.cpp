#include "UserReportEvent.h"
#include <iostream>

void UserReportEvent::execute(){
    UserStatus status = user->updateUser();
    if(status != Broken && status != Left_system) 
        eventQueue->push_back(new UserReportEvent(eventTime+2, user, eventQueue));
}

