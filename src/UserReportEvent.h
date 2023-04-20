#ifndef USER_REPORT_EVENT_H
#define USER_REPORT_EVENT_H
#include "TimedEvent.h"
#include "User.h"

class UserReportEvent: public TimedEvent{
private:
    User* user;
    
public:
    
    void execute();

    UserReportEvent(double time, User* user_, std::list<TimedEvent*>* eventQueue_):TimedEvent(time, eventQueue_), user(user_){};


};

#endif 