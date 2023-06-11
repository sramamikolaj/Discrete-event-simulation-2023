#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Logger
{
    std::ofstream file;
    std::ofstream fileDistance;
    std::ofstream fileUsers;
    std::stringstream generateString();
    int usersInSystem;
    int usersHandled;
    int usersLeft;
    int usersBroken;
    int totalSwitches;

public:
    Logger(int argc, char** argv);
    ~Logger();

    void setUsersInSystem(int users);
    void addHandled_left();
    void addHandled_broken();
    void addSwitch();
    void logSwitch(float position);
    void print();
    void printHeader(int argc, char** argv, std::vector<int> seeds);
    void log();
    void logHeader();
    void logUserData(int id, float distance, short bts);
    int  getHandled();

    
};


#endif 