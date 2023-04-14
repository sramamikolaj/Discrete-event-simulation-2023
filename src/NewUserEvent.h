#ifndef NEW_USER_EVENT_H
#define NEW_USER_EVENT_H
#include "TimedEvent.h"
#include <iostream>
#include   <list>
#include "System.h"
#include "User.h"

class NewUserEvent: public TimedEvent{

private:
    std::list<TimedEvent*>* eventQueue;
    System* system;

    void planNextNewUserEvent();
    void planNextUserReportEvent(User*);
    //std::queue<User>* usersInSystem;
public:
    void execute();

    
    NewUserEvent(double time, std::list<TimedEvent*>* eventQueue_, System* system_):TimedEvent(time), eventQueue(eventQueue_), system(system_)
    { std::cout << "NewUserEvent constructor " << time << std::endl; };

};

#endif 