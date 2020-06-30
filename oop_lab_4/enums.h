#ifndef ENUMS_H
#define ENUMS_H
enum cabinStatus
{
    MOVING,
    WAITING,
    STAYING,
    DEPARTING,
};

enum doorStatus {
    OPENING,
    OPENED,
    CLOSING,
    CLOSED
};

enum controllerStatus
{
    READYTOGO,
    BUSY
};

enum directionStatus
{
    DOWN,
    UP,
    NONE,
    stop,
};

enum buttonStatus
{
    PRESSED,
    RELEASED
};
#endif // ENUMS_H
