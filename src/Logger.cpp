#include "Logger.h"
#include <string>
Logger::Logger(int argc, char** argv)
{
   std::string filename = "results/result_"+std::string(argv[1])+"_"+argv[2]+"_"+argv[3]+".csv";
   file.open(filename, std::ios::trunc | std::ios::out);
        if (!file.is_open())
        {
            std::cerr << "Błąd otwarcia pliku " << std::endl;
        }
   file << "Users handled,users in system,users left, users broken, total switches" << std::endl;

   usersInSystem = 0;
   usersBroken = 0;
   usersHandled = 0;
   usersLeft = 0;
   totalSwitches = 0;
}
Logger::~Logger()
{
   file.close();
}

void Logger::setUsersInSystem(int users)
{
   usersInSystem = users;
}

void Logger::addHandled_left()
{
   usersLeft++;
   usersHandled++;
}

void Logger::addHandled_broken()
{
   usersBroken++;
   usersHandled++;
}

void Logger::addSwitch()
{
   totalSwitches++;
}


void Logger::print()
{
   std::stringstream ss = generateString();
   std::cout << ss.str();
}

void Logger::log()
{
   std::stringstream ss = generateString();
   file << ss.str();
}

int Logger::getHandled()
{
   return usersHandled;
}

std::stringstream Logger::generateString()
{
   std::stringstream ss;
   ss << usersHandled << ", " <<
      usersInSystem << ", " <<
      usersLeft << ", " <<
      usersBroken << ", " <<
      totalSwitches << std::endl;
   return ss;
}
