#ifndef NEW_USER_EVENT_H
#define NEW_USER_EVENT_H
#include "TimedEvent.h"
#include <iostream>
#include   <list>
#include "System.h"
#include "User.h"
#include "Simulation.h"
#include <queue>

class NewUserEvent: public TimedEvent{

private:
    
    System* system;

    void planNextNewUserEvent();
    void planNextUserReportEvent(User*);
    //std::queue<User>* usersInSystem;
public:
    ExecutionFlags execute();

    
    NewUserEvent(double time, std::list<TimedEvent*>* eventQueue_, System* system_, std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq_):TimedEvent(time, eq_), system(system_)
    { std::cout << "NewUserEvent constructor " << time << std::endl; };

};

#endif 