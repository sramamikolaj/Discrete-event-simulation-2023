#ifndef SIMULATION_H
#define SIMULATION_H
#include <queue>
#include "TimedEvent.h" 

class Simulation{

    void advanceTime();

    std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, TimedEvent() > q;

};

#endif 