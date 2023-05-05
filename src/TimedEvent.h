#ifndef TIMED_EVENT_H
#define TIMED_EVENT_H
#include<list>
#include<queue>
#include"ExecutionFlags.h"

class Compare;

class TimedEvent{
public:
    std::list<TimedEvent*>* eventQueue;
    double eventTime;
    virtual ExecutionFlags execute() = 0;
    std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq;

    TimedEvent(double time, std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq_):eventTime(time),eq(eq_){};
  
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