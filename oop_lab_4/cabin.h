#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QString>
#include "constants.h"
#include <QTimer>
#include "door.h"

class Cabin: public QObject
{
    Q_OBJECT

    enum StateOfCabin
    {
        MOVING,
        WAITING,
        STAY,
        STARTMOVING,
    };
public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

signals:
    void info(QString msg);
    void update(int floor, Direction direct, bool is_reached = false);
    void floorReached();
    void move();
    void open();

public slots:
    void showInfo(QString msg);
    void starting(int target);
private slots:
    void moving();
    void waiting();
    void stopLift();
private:
    int currentFloor = 0;
    int target = 0;
    StateOfCabin state = WAITING;
    Door door;
    QTimer movingTime;
    Direction direction = up;
};

#endif // CABIN_H
