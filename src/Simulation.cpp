#include <iostream>
#include "Simulation.h"
//#include <windows.h>
#include <string>
#include <fstream>

Simulation::Simulation(int argc, char** argv){
    seeds = getSeeds(std::stoi(argv[3]));
    system = new System(std::stod(argv[2]), seeds);
    time = 0; 
    logger = new Logger(argc, argv);
    randomTime = new Generator(seeds[0], std::stod(argv[1]));
    eq.push(new NewUserEvent(time+randomTime->randLog(), &eventQueue, system, &eq, randomTime));
    logger->log();
}

Simulation::~Simulation()
{
    delete logger;
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
            eq.push(new UserReportEvent(time+REPORT_TIME, system->addUser(), &eq));
        }
        logger->addHandled_left();
        logger->setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
        logger->print();
        logger->log();
        //std::cout << "  User handled at " << time << std::endl;
    }
    if(flags.userBrokeConnection){
        system->removeUser(flags.user);
        if(system->usersInQueue > 0){
            system->usersInQueue--;
            eq.push(new UserReportEvent(time+REPORT_TIME, system->addUser(), &eq));
        }
        logger->addHandled_broken();
        logger->setUsersInSystem(system->usersInSystem.size()+system->usersInQueue);
        logger->print();
        logger->log();
        //std::cout << "  User handled at " << time << std::endl;
    }
    if(flags.userSwitched){
        logger->addSwitch();
    }
    if(logger->getHandled() >= 300) return true;
    return false;
}

std::vector<int> Simulation::getSeeds(int setNumber)
{
    std::vector<int> numbers;
    std::ifstream file("seeds.txt");
    int seedCount = 3;
    
    if (!file) {
        std::cout << "Błąd podczas otwierania pliku." << std::endl;
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
            std::cout << "Błąd podczas wczytywania liczby " << (i + 1) << std::endl;
            break;
        }
    }
    
    file.close();
    return numbers;
    return std::vector<int>();
}
