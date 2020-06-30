#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <QFont>
#include <QString>
#include "enums.h"


enum selectStatus
{
    OPENDOORS,
    CLOSEDOORS,
    WAITINGCOMMAND
};

const int BUTTONWIDTH = 100;
const int BUTTONHEIGHT = 50;

const int WIDTHINFO = 150;
const int HEIGHTINFO = 400;

const int MOVINGTIME = 700;
const int DOORTIME = 700;
const int WAITINGTIME = 700;

const QString ARIIVEDMSG = "Arrived at floor: ";
const QString PASSIGBYMSG = "Passing floor: ";
const QString DOORSOPENINGMSG = "Openning doors";
const QString DOORSOPENEDMSG = "Doors opened";
const QString DOORSCLOSINGMSG = "Closing doors";
const QString DOORSCLOSEDMSG = "Doors closed";

const std::size_t MAXFLOORS = 12;
const int FONTSIZE = 14;
const QString FONTNAME = "Times New Roman";
const QFont FONT { FONTNAME, FONTSIZE };




const int WINDOWWIDTH = 600;
const int WINDOWHEIGHT = 600;
#endif // CONSTANTS_H
