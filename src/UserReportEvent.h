#ifndef USER_REPORT_EVENT_H
#define USER_REPORT_EVENT_H
#include "TimedEvent.h"
#include "User.h"
#include <queue>

class UserReportEvent: public TimedEvent{
private:
    User* user;
    
public:
    
    ExecutionFlags execute();

    UserReportEvent(double time, User* user_, std::priority_queue<TimedEvent*, std::vector<TimedEvent*>, Compare>* eq_):TimedEvent(time, eq_), user(user_){};


};

#endif 