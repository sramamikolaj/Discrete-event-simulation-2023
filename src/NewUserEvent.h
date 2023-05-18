#ifndef NEW_USER_EVENT_H
#define NEW_USER_EVENT_H
#include "TimedEvent.h"
#include <iostream>
#include   <list>
#include "System.h"
#include "User.h"
#include "Simulation.h"
#include <queue>
#include "Generator.h"
#include<iostream>
class NewUserEvent: public TimedEvent{

private:
    System* system;

    Generator* random;
    void planNextNewUserEvent();
    void planNextUserReportEvent(User*);
    //std::queue<User>* usersInSystem;
public:
    ExecutionFlags execute();

    
    NewUserEvent(double time, std::list<TimedEvent*>* eventQueue_, System* system_, std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq_, Generator* random_):TimedEvent(time, eq_), system(system_), random(random_)
    {
        //std::cout << "NewUserEvent at " << time << std::endl;
    };

};

#endif 