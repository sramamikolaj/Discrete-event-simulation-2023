#include <iostream>
#include "Simulation.h"


Simulation::Simulation(){
    std::cout << "Simulation constructor";
    system = new System();
    time = 0;
    eventQueue.push_front(new NewUserEvent(time+5, &eventQueue));    
}

void Simulation::run()
{
    while(true){
        if(eventQueue.empty()) break;
        eventQueue.front()->execute();
        eventQueue.pop_front();
    }
    
}
