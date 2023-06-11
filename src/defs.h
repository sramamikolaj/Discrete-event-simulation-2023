const int ALPHA = 3;
const int X_DISTANCE = 2000;
const float REPORT_TIME = 0.020f;
const int DELTA = 20;
const int BTS_POSITION[] = {0, 5000};
const int SYSTEM_CAPACITY = 60;
const double MU = 0;
const double SIGMA = 4;
const int MIN_SPEED = 5;
const int MAX_SPEED = 50;

enum UserStatus
{
    NO_NEWS = 0,
    CONNECTION_BROKEN,
    LEFT_SYSTEM,
    BTS_SWITCH_REQUEST
};

