#include "button.h"


Button::Button(QWidget *parent) : QPushButton(parent) {
    state = RELEASED;
    floor = 0;
    connect(this, &Button::clicked, this, &Button::pressed);
    connect(this, &Button::reset, this, &Button::released);
}


void Button::setFloorNum(std::size_t nfloor)
{
    floor = nfloor;
}

void Button::pressed()
{
    if (state == RELEASED)
    {
        state = PRESSED;
        setEnabled(false);

        emit requestFloor(floor);
    }
}


void Button::released()
{
    if (state == PRESSED)
    {
        state = RELEASED;
        setEnabled(true);

    }
}
