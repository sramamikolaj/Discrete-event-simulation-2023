#include "NewUserEvent.h"
#include "UserReportEvent.h"

ExecutionFlags NewUserEvent::execute(){
    ExecutionFlags returnFlags; 
    User* newUser = system->addUser();
    if(newUser){
        planNextUserReportEvent(newUser);
    }else{
        returnFlags.systemFull = true;
    };
    planNextNewUserEvent();

    
    return returnFlags;

}
void NewUserEvent::planNextNewUserEvent(){
    double test = eventTime+random->randLog(LAMBDA);
    eq->push(new NewUserEvent(test, eventQueue, system, eq, random));
}
void NewUserEvent::planNextUserReportEvent(User* user){
    eq->push(new UserReportEvent(eventTime+REPORT_TIME*0.001, user, eq));
}