#include <iostream>
#include "Simulation.h"
//#include <windows.h>
#include <string>
#include <fstream>

Simulation::Simulation(int argc, char** argv){
    time        = 0; 
    seeds       = readSeeds(std::stoi(argv[3]));
    system      = new System(std::stod(argv[2]), seeds);
    logger      = new Logger(argc, argv);
    randomTime  = new Generator(seeds[0], std::stod(argv[1]));
    eventQueue.push(new NewUserEvent(time+randomTime->randLog(), system, &eventQueue, randomTime));
    logger  ->log();
}

Simulation::~Simulation()
{
    delete logger;
    delete system;
    delete randomTime;
}

void Simulation::run()
{
    while(true){
        if(eventQueue.empty() || logger->getHandled() > USER_LIMIT) break;
        advanceTime();
        ExecutionFlags ef = eventQueue.top()->execute();
        delete eventQueue.top();
        eventQueue.pop();
        if(ef.anyFlag()) handleConditionalEvents(ef);
    }
}

void Simulation::advanceTime(){
    time = eventQueue.top()->eventTime;
}

void Simulation::handleConditionalEvents(ExecutionFlags flags){
    if(flags.systemFull){
        system->usersInQueue++;
    }
    if(flags.userLeft){
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eventQueue.push(new UserReportEvent(time+REPORT_TIME, system->addUser(), &eventQueue));
        }
        logger->addHandled_left();
        logger->setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
        logger->print();
        logger->log();
    }
    if(flags.userBrokeConnection){
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eventQueue.push(new UserReportEvent(time+REPORT_TIME, system->addUser(), &eventQueue));
        }
        logger->addHandled_broken();
        logger->setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
        logger->print();
        logger->log();
    }
    if(flags.userSwitched){
        logger->addSwitch();
    }
}

std::vector<int> Simulation::readSeeds(int setNumber)
{
    std::vector<int> numbers;
    std::ifstream file("seeds.txt");
    int seedCount = 3;
    
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return numbers;
    }

    std::string line;
    for (int i = 0; i < seedCount*setNumber; ++i)
        std::getline(file, line);

    int number;
    for (int i = 0; i < 3; ++i) {
        if (file >> number) {
            std::cout << "Seed " << i << ": " << number << std::endl;
            numbers.push_back(number);
        } else {
            std::cout << "Error reading seeds" << std::endl;
            break;
        }
    }
    file.close();
    return numbers;
}
