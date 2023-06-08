const int ALPHA = 3;
const int X_DISTANCE = 2000;
const float REPORT_TIME = 0.020;
const int DELTA = 18;
const int BTS_POSITION[] = {0, 5000};
const int USER_LIMIT = 1000;

enum UserStatus
{
    NO_NEWS = 0,
    CONNECTION_BROKEN,
    LEFT_SYSTEM,
    BTS_SWITCHED
};

