#ifndef TIMED_EVENT_H
#define TIMED_EVENT_H


class TimedEvent{
public:
    double eventTime;
    virtual void execute() = 0;

    TimedEvent(double time):eventTime(time){};

    bool operator()(const TimedEvent* a, const TimedEvent* b )
    {
        return a->eventTime > b->eventTime;
    }
};

#endif 