#include "UserReportEvent.h"
#include <iostream>

void UserReportEvent::execute(){
    std::cout << user->updateUser() << std::endl;
}

