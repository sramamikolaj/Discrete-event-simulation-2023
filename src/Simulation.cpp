#include <iostream>
#include "Simulation.h"
//#include <windows.h>

Simulation::Simulation(){
    system = new System();
    time = 0; 
    randomTime = new Generator(241673);
    eq.push(new NewUserEvent(time+5, &eventQueue, system, &eq, randomTime));
}

void Simulation::run()
{
    while(true){
        if(eq.empty()) break;
        advanceTime();
        ExecutionFlags ef = eq.top()->execute();
        delete eq.top();
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
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eq.push(new UserReportEvent(time+1, system->addUser(), &eq));
        }
    }
    if(flags.userBrokeConnection){
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eq.push(new UserReportEvent(time+1, system->addUser(), &eq));
        }
    }
}
