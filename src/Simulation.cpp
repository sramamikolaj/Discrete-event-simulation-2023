#include <iostream>
#include "Simulation.h"
//#include <windows.h>

Simulation::Simulation(){
    system = new System();
    time = 0; 
    randomTime = new Generator(241673);
    eq.push(new NewUserEvent(randomTime->randLog(LAMBDA), &eventQueue, system, &eq, randomTime));
    logger.log();
}

void Simulation::run()
{
    while(true){
        if(eq.empty()) break;
        advanceTime();
        ExecutionFlags ef = eq.top()->execute();
        delete eq.top();
        eq.pop();

        if(ef.anyFlag()) {
            if(handleConditionalEvents(ef)) 
            {
                return;
            }
        }
        if(logger.getHandled() == 247){
            std::cout << "Hi";
        }
    }
}

void Simulation::advanceTime(){
    time = eq.top()->eventTime;
}

bool Simulation::handleConditionalEvents(ExecutionFlags flags){
    if(flags.systemFull){
        system->usersInQueue++;
    }
    if(flags.userLeft){
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eq.push(new UserReportEvent(time+REPORT_TIME*0.001, system->addUser(), &eq));
        }
        logger.addHandled_left();
        logger.setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
        logger.log();
    }
    if(flags.userBrokeConnection){
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eq.push(new UserReportEvent(time+REPORT_TIME*0.001, system->addUser(), &eq));
        }
        logger.addHandled_broken();
        logger.setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
        logger.log();
    }
    if(flags.userSwitched){
        logger.addSwitch();
    }
    if(logger.getHandled() >= 3000) return true;
    return false;
}
