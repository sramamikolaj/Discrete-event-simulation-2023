#include "NewUserEvent.h"
#include "UserReportEvent.h"

ExecutionFlags NewUserEvent::execute(){
    ExecutionFlags returnFlags; 
    std::cout << "NewEventUser execute" << std::endl;
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
    std::cout << "NewEventUser planNextEvent for " << eventTime+5 << std::endl;
    eq->push(new NewUserEvent(eventTime+20, eventQueue, system, eq));
}
void NewUserEvent::planNextUserReportEvent(User* user){
    std::cout << "NewEventUser planUserReportEvent for " << eventTime+3 << std::endl;
    eq->push(new UserReportEvent(eventTime+1, user, eq));
}