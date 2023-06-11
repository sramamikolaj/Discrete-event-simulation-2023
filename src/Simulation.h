#ifndef SIMULATION_H
#define SIMULATION_H
#include <queue>  
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include "TimedEvent.h" 
#include "System.h"
#include "NewUserEvent.h"
#include "UserReportEvent.h"
#include "ExecutionInfo.h"
#include "Logger.h"
#include <vector>


class Simulation{
    System*     system;
    double      time;
    Logger*     logger;
    std::vector<int> seeds;
    Generator*       randomTime;
    int handledRange[2];

    void advanceTime();
    void handleConditionalEvents(ExecutionInfo flags);
    std::vector<int> readSeeds(int setNumber);

    std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare> eventQueue;
public: 
    Simulation(int argc, char** argv);
    ~Simulation();
    void run();

};

#endif 