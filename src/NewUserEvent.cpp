#include "NewUserEvent.h"
#include "UserReportEvent.h"
#include "iostream"

NewUserEvent::NewUserEvent(double time, System *system_, std::priority_queue<TimedEvent *, std::vector<TimedEvent *>, Compare> *eq_, Generator *random_)
    :TimedEvent(time, eq_)
{
    system = system_;
    random = random_;
}

ExecutionInfo NewUserEvent::execute(){
    ExecutionInfo returnInfo; 
    User* newUser = system->addUser();
    if(newUser){
        planNextUserReportEvent(newUser);
    }else{
        returnInfo.systemFull = true;
    };
    planNextNewUserEvent();

    return returnInfo;
}

void NewUserEvent::planNextNewUserEvent()
{
    eq->push(new NewUserEvent(eventTime+random->randLog(), system, eq, random));
}

void NewUserEvent::planNextUserReportEvent(User* user){
    eq->push(new UserReportEvent(eventTime+REPORT_TIME, user, eq));
}