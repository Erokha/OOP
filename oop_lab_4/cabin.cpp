#include "cabin.h"


Cabin::Cabin(QObject *parent) {
    Q_UNUSED(parent);
    movingTime.setSingleShot(true);

    connect(&movingTime, &QTimer::timeout, this, &Cabin::moving);
    connect(this, &Cabin::move,this, &Cabin::moving);
    connect(this, &Cabin::floorReached,this, &Cabin::stopLift);
    connect(&door, &Door::doorsClosed, this, &Cabin::staying);
    connect(this, &Cabin::open, &door, &Door::opening);
    connect(this, &Cabin::close, &door, &Door::closing);
    connect(&door, &Door::info, this, &Cabin::logUpdate);
    connect(&door, &Door::errorOpening, this, &Cabin::errorOpening);
    connect(&door, &Door::errorClosing, this, &Cabin::errorClosing );


}


void Cabin::moving() {
    if (state == MOVING || state == DEPARTING)
    {

       if(state == MOVING) {
            currentFloor+=step;
            emit update(currentFloor, false);
       }
       else if(state == DEPARTING) {
           state = MOVING;
       }


       if (currentFloor == target) {
           emit floorReached();
       }
       else {
           emit logUpdate(PASSIGBYMSG + QString::number(currentFloor + 1));
           movingTime.start(MOVINGTIME);
       }

    }


}


void Cabin::stopLift() {
    if (state == MOVING)
    {
        emit logUpdate(ARIIVEDMSG + QString::number(currentFloor + 1));

        state = STAYING;
        emit update(currentFloor, true);
        emit open();
    }

}


void Cabin::staying(selectStatus st) {
    if (state != STAYING) {
        if (st == CLOSEDOORS) {
            emit errorClosing();
        }
        else {
            emit errorOpening();
        }
        return;
    }

    if (st == WAITING) {
        state = WAITING;
        emit update(currentFloor, true);
    } else if (st == OPENDOORS) {
        emit open();
    } else if (st == CLOSEDOORS) {
        emit close();
    }


}


void Cabin::starting(int targetFloor, directionStatus dir) {
     if (state == WAITING) {
        state = DEPARTING;
        target = targetFloor;

        if (dir == UP){
            step = 1;
        } else if (dir == DOWN) {
            step =-1;
        }

        emit move();
    }

    else {
         emit unableToReach(targetFloor);
    }
}

