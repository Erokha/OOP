#include "cabin.h"


Cabin::Cabin(QObject *parent) {
    Q_UNUSED(parent);
    connect(&movingTime, &QTimer::timeout, this, &Cabin::moving);

    connect(this, &Cabin::move, this, &Cabin::moving);
    connect(this, &Cabin::floorReached, this, &Cabin::stopLift);
    connect(&door, &Door::doorsClosed, this, &Cabin::waiting);
    connect(this, &Cabin::open, &door, &Door::opening);
    connect(&door, &Door::info, this, &Cabin::showInfo);

}


void Cabin::moving() {
    if (state == MOVING) {
        if (currentFloor == target) {
            emit floorReached();
        } else {

            emit info(THROUGHFLOOR + QString::number(currentFloor + 1));
            int changeFloor = 0;
            if (currentFloor < target) {
                direction = up;
                changeFloor = 1;
            } else {
                direction = down;
                changeFloor = -1;
            }
            currentFloor += changeFloor;

            emit update(currentFloor, direction, false);
            movingTime.start(MOVINGTIME);
        }
    } else if (state == STARTMOVING) {
        if (currentFloor == target) {
            emit floorReached();
        } else {
            state = MOVING;
            emit move();
        }
    }
}


void Cabin::stopLift() {
    if (state == MOVING)
    {
        emit info(STAYONFLOOR + QString::number(currentFloor + 1));
        state = STAY;
        emit update(currentFloor, direction, true);
        emit open();
    }
}

void Cabin::waiting() {
    if (state == STAY)
    {
        state = WAITING;
        emit update(currentFloor, direction, true);
    }
}

void Cabin::starting(int targetN) {
    if (state == WAITING && targetN == currentFloor){
        state = STAY;
        emit update(currentFloor, direction, true);
        emit open();
    }
    if (state == WAITING) {
        state = STARTMOVING;
        target = targetN;
        emit move();
    }
}

void Cabin::showInfo(QString message) {
    emit info(message);
}
