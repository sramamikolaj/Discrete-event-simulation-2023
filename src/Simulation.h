#ifndef SIMULATION_H
#define SIMULATION_H
#include <queue>  
#include <list>
#include "TimedEvent.h" 
#include "System.h"
#include "NewUserEvent.h"
#include "UserReportEvent.h"
#include "ExecutionFlags.h"
#include "Logger.h"
#include <vector>

class Simulation{
    System*     system;
    double      time;
    Logger*     logger;
    std::vector<int> seeds;
    Generator*       randomTime;
    void advanceTime();
    void handleConditionalEvents(ExecutionFlags flags);
    std::vector<int> readSeeds(int setNumber);

    std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare> eventQueue;
public: 
    Simulation(int argc, char** argv);
    ~Simulation();
    void run();

};

#endif 