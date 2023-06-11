#include "Logger.h"
#include <string>

Logger::Logger(int argc, char** argv)
{
   usersInSystem  = 0;
   usersBroken    = 0;
   usersHandled   = 0;
   usersLeft      = 0;
   totalSwitches  = 0;

   std::string filename = "results/result_"+std::string(argv[1])+"_"+argv[2]+"_"+argv[3]+".csv";
   file.open(filename, std::ios::trunc | std::ios::out);
   if (!file.is_open()) std::cerr << "Eror opening file" << std::endl;
   file << "Users handled, users in system, users left, users broken, total switches" << std::endl;

   filename = "results_distance/result_"+std::string(argv[1])+"_"+argv[2]+"_"+argv[3]+".csv";
   fileDistance.open(filename, std::ios::trunc | std::ios::out);
   if (!fileDistance.is_open()) std::cerr << "Eror opening file" << std::endl;
   fileDistance << "BTS 1 -> 2 switch position" << std::endl;

   filename = "results_user/result_"+std::string(argv[1])+"_"+argv[2]+"_"+argv[3]+".csv";
   fileUsers.open(filename, std::ios::trunc | std::ios::out);
   if (!fileUsers.is_open()) std::cerr << "Eror opening file" << std::endl;
   fileUsers << "user, distance, bts" << std::endl;
}
Logger::~Logger()
{
   file.close();
   fileDistance.close();
   fileUsers.close();
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

void Logger::logSwitch(float position)
{
   fileDistance << position << std::endl;
}

void Logger::print()
{
   std::stringstream ss = generateString();
   std::cout << ss.str();
}

void Logger::printHeader(int argc, char** argv, std::vector<int> seeds)
{
   std::cout << "Lambda = " << argv[1] << std::endl;
   std::cout << "TimeToTrigger = " << argv[2] << " ms" << std::endl;
   std::cout << "Seeds dataset is " << argv[3] << std::endl;
   std::cout << "Handled user range from " << argv[4] << " to " << argv[5] << std::endl;
   std::cout << "Seed_1 = " << seeds[0] << std::endl;
   std::cout << "Seed_2 = " << seeds[1] << std::endl;
   std::cout << "Seed_3 = " << seeds[2] << std::endl << std::endl;

   std::cout << "Users handled, users in system, users left, users broken, total switches" << std::endl;
}

void Logger::log()
{
   std::stringstream ss = generateString();
   file << ss.str();
}

void Logger::logHeader()
{
}

void Logger::logUserData(int id, float distance, short bts)
{
   fileUsers << id << ", " << distance << ", " << bts << std::endl;
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
