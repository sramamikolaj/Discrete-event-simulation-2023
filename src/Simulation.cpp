#include <iostream>
#include "Simulation.h"
#include <unistd.h> 
//#include <windows.h>

Simulation::Simulation(){
    system = new System();
    time = 0; 
    eq.push(new NewUserEvent(time+5, &eventQueue, system, &eq));
}

void Simulation::run()
{
    while(true){
        if(eq.empty()) break;
        advanceTime();
        ExecutionFlags ef = eq.top()->execute();
        eq.pop();

        if(ef.anyFlag()) handleConditionalEvents(ef);

        
    }
    
}

void Simulation::advanceTime(){
    time = eq.top()->eventTime;
    std::cout << "Advance time to " << time << std::endl;
}
void Simulation::handleConditionalEvents(ExecutionFlags flags){
    if(flags.systemFull){
        system->usersInQueue++;
    }
    if(flags.userLeft){
        eq.push(new UserReportEvent(time+1, system->addUser(), &eq));
    }
    if(flags.userBrokeConnection){
        eq.push(new UserReportEvent(time+1, system->addUser(), &eq));
    }
}
