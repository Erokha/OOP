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
    else if (state == CLOSING) {
        state = OPENING;
        emit info(DOORSOPENINGMSG);
        timeToClose.stop();
        timeToOpen.start(DOORTIME);
    }

    else {
        emit errorOpening();
    }
}


void Door::opened()
{
    if (state == OPENING) {
        state = OPENED;
        emit info(DOORSOPENEDMSG);
        emit errorOpening();
        timeToWait.start(WAITINGTIME);
    }
}

void Door::closing()
{
    if (state == OPENED) {
        state = CLOSING;
        emit info(DOORSCLOSINGMSG);
        timeToWait.stop();
        timeToClose.start(DOORTIME);
    }

    else {
        emit errorClosing();;
    }
}

void Door::closed() {
    if (state == CLOSING) {
        state = CLOSED;
        emit errorClosing();
        emit info(DOORSCLOSEDMSG);

        emit doorsClosed(WAITINGCOMMAND);
    }
}
