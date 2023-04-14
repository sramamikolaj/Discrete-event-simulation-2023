#ifndef NEW_USER_EVENT_H
#define NEW_USER_EVENT_H
#include "TimedEvent.h"
#include <iostream>
#include   <list>

class NewUserEvent: public TimedEvent{

private:
    std::list<TimedEvent*>* eventQueue;

    void planNextEvent();
    //std::queue<User>* usersInSystem;
public:
    void execute();

    NewUserEvent(double time, std::list<TimedEvent*>* eventList):TimedEvent(time), eventQueue(eventList){ std::cout << "NewUserEvent constructor" << std::endl; };

};

#endif 