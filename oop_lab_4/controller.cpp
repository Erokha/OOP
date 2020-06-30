#include "controller.h"

Controller::Controller(QWidget *parent) :
    QWidget(parent)
{

}


Controller::~Controller() {

}

void Controller::setTarget(std::size_t floor) {
    if (state == READYTOGO) {
        state = BUSY;

        if (currentFloor > floor) {
            direction = DOWN;
        } else {
            direction = UP;
        }
        emit sendTarget(floor, direction);
    }
    else {
        emit unableToGet(floor);
    }
}



void Controller::updateInfo(std::size_t floor,  bool reached)
{   
    if(state == BUSY) {
        currentFloor = floor;
        if (reached) {
            emit floorReached(floor);
            state = READYTOGO;
        }
    }
}

int Controller::getCurrentFloor() {
    return currentFloor;
}


QWidget *Controller::GetWidget() {
    return this;
}


