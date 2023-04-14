#include "NewUserEvent.h"

void NewUserEvent::execute(){
    std::cout << "NewEventUser execute";
    planNextEvent();
}
void NewUserEvent::planNextEvent(){
    std::cout << "NewEventUser planNextEvent" << std::endl;
    eventQueue->push_front(new NewUserEvent(10, eventQueue));
}