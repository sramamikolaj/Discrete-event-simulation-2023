#ifndef SIMULATION_H
#define SIMULATION_H

#include <list>
#include "TimedEvent.h" 
#include "System.h"
#include "NewUserEvent.h"

class Simulation{
    System* system;
    double time;
    Conditions conditions;
    
    void advanceTime();
    void handleConditionalEvents();

    std::list<TimedEvent*> eventQueue;

public: 
    Simulation();
    
    void run();

};

#endif 