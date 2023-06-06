#include <string>

const int ALPHA = 3;
const int X_DISTANCE = 2000;
//const float TTT = 0.2;
const float REPORT_TIME = 0.020;
const int DELTA = 20;
const int BTS_POSITION[] = {0, 5000};
const int USER_LIMIT = 60;

enum UserStatus
{
    NO_NEWS = 0,
    CONNECTION_BROKEN,
    LEFT_SYSTEM,
    BTS_SWITCHED
};

