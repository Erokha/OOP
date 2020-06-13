#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <QFont>
#include <QString>

enum Direction
{
    down,
    up,
    staying,
    stop,
};


//const QString CABINSHEADER = "Button";
const std::size_t MAXFLOORS = 16;
const int FONTSIZE = 16;
const QString FONTNAME = "Times New Roman";
const QFont FONT { FONTNAME, FONTSIZE };

const int WIDTH = 100;
const int HEIGHT = 30;

const int WIDTHINFO = 150;
const int HEIGHTINFO = 400;

const int MOVINGTIME = 1500;
const int DOORTIME = 1500;

const QString STAYONFLOOR = "We are staying on the floor:";
const QString THROUGHFLOOR = "We are going through:";
const QString DOORSOPENINGMSG = "Attention! Doors are opening!";
const QString DOORSOPENEDMSG = "Doors are opened!";
const QString DOORSCLOSINGMSG = "Attention! Doors are closing!";
const QString DOORSCLOSEDMSG = "Doors are closed";



const int WINDOWWIDTH = 600;
const int WINDOWHEIGHT = 600;
#endif // CONSTANTS_H
