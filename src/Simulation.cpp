#include <iostream>
#include "Simulation.h"
#include <unistd.h> //temp for sleep

Simulation::Simulation(){
    std::cout << "Simulation constructor" << std::endl;
    system = new System();
    time = 0;
    eventQueue.push_front(new NewUserEvent(time+5, &eventQueue, system));    
}

void Simulation::run()
{
    //problem ze struktura
    while(true){
        if(eventQueue.empty()) break;
        advanceTime();
        eventQueue.front()->execute();
        eventQueue.pop_front();


        usleep(1000000); //wait 1s for debug
    }
    
}
void Simulation::advanceTime(){
    time = eventQueue.front()->eventTime;
    std::cout << "Advance time to " << time << std::endl;
}
