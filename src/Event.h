#ifndef EVENT_H
#define EVENT_H


class Event(){

public:
    double eventTime;
    virtual void execute() = 0;

    Event(double time):eventTime(time){};
}



#endif 