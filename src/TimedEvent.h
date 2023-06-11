#ifndef TIMED_EVENT_H
#define TIMED_EVENT_H

#include <list>
#include <queue>
#include "ExecutionInfo.h"
class Compare;

class TimedEvent{
public:
    TimedEvent(double time, std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq_):eventTime(time),eq(eq_){};
    double eventTime;
    virtual ExecutionInfo execute() = 0;
protected:
    std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq;
};

class Compare {
    public:
       bool operator()(TimedEvent* a, TimedEvent* b){
           if(a->eventTime > b->eventTime){
               return true;
           }
           return false;
      }
};

#endif 