#ifndef NEW_USER_EVENT_H
#define NEW_USER_EVENT_H
#include "TimedEvent.h"

class NewUserEvent: public TimedEvent{
public:
    void execute();

    NewUserEvent(double time):TimedEvent(time){};
};

#endif 