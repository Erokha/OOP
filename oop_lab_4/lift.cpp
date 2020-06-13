#include "lift.h"
#include <QObject>
#include "controller.h"
#include "cabin.h"

Elevator::Elevator(QObject *parent) : QObject(parent) {
    connect(&controller, &Controller::sendTarget,
            &cabin,  &Cabin::starting);
}

QWidget *Elevator::GetWidget() {
    return &controller;
}


