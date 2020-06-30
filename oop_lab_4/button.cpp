#include "button.h"


BaseButton::BaseButton(QWidget *widjet): QPushButton(widjet) {

}


BaseButton::~BaseButton() {

}

DoorsOpeneningButton::DoorsOpeneningButton(QWidget *widget): BaseButton(widget) {
    status = RELEASED;
    connect(this, SIGNAL(clicked()), SLOT(pressed()));
    connect(this, SIGNAL(reset()), SLOT(released()));
}


void DoorsOpeneningButton::pressed()
{
    if (status == RELEASED)
    {
        status = PRESSED;
        setEnabled(false);

        emit callOpenDoors(OPENDOORS);
    }
}

void DoorsOpeneningButton::released()
{
    if (status == PRESSED)
    {
        status = RELEASED;
        setEnabled(true);
    }
}

DoorsClosingButton::DoorsClosingButton(QWidget *widget): BaseButton(widget) {
    status = RELEASED;
    connect(this, SIGNAL(clicked()), SLOT(pressed()));
    connect(this, SIGNAL(reset()), SLOT(released()));
}

void DoorsClosingButton::released()
{
    if (status == PRESSED)
    {
        status = RELEASED;
        setEnabled(true);
    }
}

void DoorsClosingButton::pressed()
{
    if (status == RELEASED)
    {
        status = PRESSED;
        setEnabled(false);

        emit callCloseDoors(CLOSEDOORS);
    }
}

FloorButton::FloorButton(QWidget *parent) :BaseButton(parent) {
    status = RELEASED;
    floor = 0;
    connect(this, &FloorButton::clicked,
            this, &FloorButton::pressed);

    connect(this, &FloorButton::reset,
            this, &FloorButton::released);
}


void FloorButton::setFloorNum(std::size_t floor_num)
{
    floor = floor_num;
}

void FloorButton::pressed()
{
    if (status == RELEASED)
    {
        setStyleSheet("border: 1px solid red;");
        status = PRESSED;
        setEnabled(false);

        emit requestFloor(floor);
    }
}


void FloorButton::released()
{
    if (status == PRESSED)
    {
        setStyleSheet("border 1px solid grey");
        status = RELEASED;
        setEnabled(true);
    }
}
