#ifndef SIMULATION_H
#define SIMULATION_H
#include <queue>  
#include <list>
#include "TimedEvent.h" 
#include "System.h"
#include "NewUserEvent.h"

class Compare {
    public:
       bool operator()(TimedEvent* a, TimedEvent* b){
           if(a->eventTime > b->eventTime){
               return true;
           }
           return false;
      }
};

class Simulation{
    System* system;
    double time;
    Conditions conditions;
    
    void advanceTime();
    void handleConditionalEvents();

    std::list<TimedEvent*> eventQueue;
    //std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare> eq;

public: 
    Simulation();
    
    void run();

};

#endif 