#ifndef USER_REPORT_EVENT_H
#define USER_REPORT_EVENT_H
#include "TimedEvent.h"

class UserReportEvent: public TimedEvent{
public:
    void execute();

    UserReportEvent(double time):TimedEvent(time){};

private:
    
};

#endif 