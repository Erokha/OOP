#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QString>
#include "constants.h"
#include <QTimer>
#include "door.h"
#include "enums.h"

class Cabin: public QObject
{
    Q_OBJECT


public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

signals:
    void logUpdate(QString msg);
    void update(int floor, bool isReached = false);
    void floorReached();
    void move();
    void open();
    void close();
    void errorOpening();
    void errorClosing();
    void unableToReach(size_t floor);

public slots:
    void starting(int target, directionStatus dir);
    void staying(selectStatus st);
private slots:
    void moving();
    void stopLift();
private:
    int currentFloor = 0;
    int target = 0;
    int step;
    cabinStatus state = WAITING;
    Door door;
    QTimer movingTime;
    directionStatus direction = UP;
};

#endif // CABIN_H
