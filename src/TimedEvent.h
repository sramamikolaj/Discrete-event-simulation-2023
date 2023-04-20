#ifndef TIMED_EVENT_H
#define TIMED_EVENT_H
#include<list>

class TimedEvent{
public:
    std::list<TimedEvent*>* eventQueue;
    double eventTime;
    virtual void execute() = 0;

    TimedEvent(double time, std::list<TimedEvent*>* eventQueue_):eventTime(time),eventQueue(eventQueue_){};

    //temp?
    bool operator <(const TimedEvent & te) const
    {
        return eventTime > te.eventTime;
    }
};

#endif 