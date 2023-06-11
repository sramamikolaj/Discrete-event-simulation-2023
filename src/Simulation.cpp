#include <iostream>
#include "Simulation.h"
#include <string>
#include <fstream>

Simulation::Simulation(int argc, char** argv){
    time        = 0; 
    seeds       = readSeeds(std::stoi(argv[3]));
    system      = new System(std::stod(argv[2]), seeds);
    logger      = new Logger(argc, argv);
    logger -> printHeader(argc, argv, seeds);
    randomTime  = new Generator(seeds[0], std::stod(argv[1]));
    eventQueue.push(new NewUserEvent(time+randomTime->randLog(), system, &eventQueue, randomTime));
    handledRange[0] = std::stoi(argv[4]); 
    handledRange[1] = std::stoi(argv[5]); 
    if(handledRange[0] == 0) logger->log();
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
        if(eventQueue.empty() || logger->getHandled() >= handledRange[1]) break;
        advanceTime();
        ExecutionInfo executionInfo = eventQueue.top()->execute();
        delete eventQueue.top();
        eventQueue.pop();
        //To log user data:
        //if(executionInfo.user) logger -> logUserData((int)executionInfo.user, executionInfo.user->getPosition(), executionInfo.user->getBTS());
        if(executionInfo.anyFlag()) handleConditionalEvents(executionInfo);
    }
}

void Simulation::advanceTime(){
    time = eventQueue.top()->eventTime;
}

void Simulation::handleConditionalEvents(ExecutionInfo ei){
    bool noEventTriggered;
    do{
        noEventTriggered = true;
        //Event: system is full, adding new user failed 
        if(ei.systemFull){
            system->usersInQueue++;
            ei.systemFull    = false;
            noEventTriggered = false;
        }
        //Event: user left the system due to distance limit
        if(ei.userLeft){
            system->removeUser(ei.user);
            logger->addHandled_left();
            logger->setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
            if(logger->getHandled() >= handledRange[0]){
                logger->print();
                logger->log();
            } 
            ei.userLeft = false;
            noEventTriggered = false;
        }
        //Event: user broke connection due to power difference
        if(ei.userBrokeConnection){
            system->removeUser(ei.user);
            logger->addHandled_broken();
            logger->setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
            if(logger->getHandled() >= handledRange[0]){
                logger->print();
                logger->log();
            } 
            ei.userBrokeConnection = false;
            noEventTriggered = false;
        }
        //Event: user requests a switch to other station
        if(ei.userRequestsSwitch){
            if(ei.user->getBTS() == 0) logger->logSwitch(ei.user->getPosition());
            logger->addSwitch();
            system->switchBTS(ei.user);
            ei.userRequestsSwitch = false;
            noEventTriggered = false;
        }
        //Event: there are free slots in the system and queue is not empty
        if(system->usersInSystem.size() < SYSTEM_CAPACITY && system->usersInQueue > 0){
            system->usersInQueue--;
            eventQueue.push(new UserReportEvent(time+REPORT_TIME, system->addUser(), &eventQueue));
            noEventTriggered = false;
        }
    } while(!noEventTriggered);
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
