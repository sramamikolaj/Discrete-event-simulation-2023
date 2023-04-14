#include "NewUserEvent.h"
#include "UserReportEvent.h"

void NewUserEvent::execute(){
    std::cout << "NewEventUser execute" << std::endl;
    User* newUser = system->addUser();
    if(newUser){
        planNextUserReportEvent(newUser);
    }else{
        //flaga
    };
    planNextNewUserEvent();
}
void NewUserEvent::planNextNewUserEvent(){
    std::cout << "NewEventUser planNextEvent for " << eventTime+5 << std::endl;
    eventQueue->push_back(new NewUserEvent(eventTime+20, eventQueue, system));
}
void NewUserEvent::planNextUserReportEvent(User* user){
    std::cout << "NewEventUser planUserReportEvent for " << eventTime+3 << std::endl;
    eventQueue->push_back(new UserReportEvent(eventTime+1, user));
}