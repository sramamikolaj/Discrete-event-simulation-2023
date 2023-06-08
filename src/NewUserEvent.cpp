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
    double randomTi = random->randLog();
    //std::cout << randomTi << std::endl;
    eq->push(new NewUserEvent(eventTime+randomTi, system, eq, random));
}
void NewUserEvent::planNextUserReportEvent(User* user){
    eq->push(new UserReportEvent(eventTime+REPORT_TIME, user, eq));
}