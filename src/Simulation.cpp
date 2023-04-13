#include "Simulation.h"


Simulation::Simulation(){
    system = new System();
    time = 0;
    eventQueue.push_front(new NewUserEvent(time+5));

    std::cout << "Simulation constructor";
}

void Simulation::run()
{
    while(true){
        (eventQueue.front())->execute();
        eventQueue.pop_front();
    }
    
}
