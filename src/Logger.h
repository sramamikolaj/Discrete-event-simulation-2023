#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Logger
{
   public:
      Logger(int argc, char** argv);
      ~Logger();

      void setUsersInSystem(int users);
      void addHandled_left();
      void addHandled_broken();
      void addSwitch();

      void print();

      void log();
      int getHandled();

  private:
      std::ofstream file;
      std::stringstream generateString();

      int usersInSystem;
      int usersHandled;
      int usersLeft;
      int usersBroken;
      int totalSwitches;
};


#endif 