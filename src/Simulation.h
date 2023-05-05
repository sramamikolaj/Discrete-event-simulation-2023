#ifndef SIMULATION_H
#define SIMULATION_H
#include <queue>  
#include <list>
#include "TimedEvent.h" 
#include "System.h"
#include "NewUserEvent.h"
#include "UserReportEvent.h"
#include "ExecutionFlags.h"


class Simulation{
    System* system;
    double time;
    Conditions conditions;
    
    void advanceTime();
    void handleConditionalEvents(ExecutionFlags flags);

    std::list<TimedEvent*> eventQueue;
    std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare> eq;

public: 
    Simulation();
    
    void run();

};

#endif 