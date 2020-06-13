#include "door.h"


Door::Door(QObject *parent)
{
    Q_UNUSED(parent);
    state = CLOSED ;
    connect(&timeToOpen, &QTimer::timeout, this, &Door::opened);
    connect(&timeToWait, &QTimer::timeout, this, &Door::closing);
    connect(&timeToClose, &QTimer::timeout, this, &Door::closed);
}


void Door::opening()
{
    if (state == CLOSED)
    {
        state = OPENING;
        emit info(DOORSOPENINGMSG);

        timeToOpen.start(DOORTIME);
    }
}


void Door::opened()
{
    if (state == OPENING) {
        state = OPENED;
        emit info(DOORSOPENEDMSG);

        timeToWait.start(DOORTIME);
    }
}

void Door::closing()
{
    if (state == OPENED) {
        state = CLOSING;
        emit info(DOORSCLOSINGMSG);

        timeToClose.start(DOORTIME);
    }
}

void Door::closed() {
    if (state == CLOSING) {
        state = CLOSED;
        emit info(DOORSCLOSEDMSG);

        emit doorsClosed();
    }
}
