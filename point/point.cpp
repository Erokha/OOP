#include "../point/point.h"
#include "math.h"

// Задать точке point координаты x, y
void initPoint(struct myPoint* point, double x, double y, double z)
{
    point->x = x;
    point->y = y;
    point->z = z;
}

void copyPoint(myPoint* source, myPoint* dest)
{
    dest->x = source->x;
    dest->y = source->y;
    dest->z = source->z;
}

void rotatePointByX(myPoint* pointToRotate, myPoint* pointRegarding, double alpha)
{
    double angle = alpha * 3.14 / 180;
    double newx, newy, newz;
    newx = pointToRotate->x;
    newy = pointRegarding->y + (pointToRotate->y - pointRegarding->y) * cos(angle) + (pointRegarding->z - pointToRotate->z) * sin(angle);
    newz = pointRegarding->z + (pointToRotate->y - pointRegarding->y) * sin(angle) + (pointToRotate->z - pointRegarding->z) * cos(angle);
    pointToRotate->x = newx;
    pointToRotate->y = newy;
    pointToRotate->z = newz;
}

void rotatePointByY(myPoint* pointToRotate, myPoint* pointRegarding, double alpha)
{
    double newx, newy, newz;
    double angle = alpha * 3.14 / 180;
    newx = pointRegarding->x+(pointToRotate->x-pointRegarding->x)*cos(angle)+(pointToRotate->z-pointRegarding->z)*sin(angle);
    newy = pointToRotate->y;
    newz = pointRegarding->z+(pointRegarding->x-pointToRotate->x)*sin(angle)+(pointToRotate->z-pointRegarding->z)*cos(angle);
    pointToRotate->x = newx;
    pointToRotate->y = newy;
    pointToRotate->z = newz;
}


void pointZoom(myPoint* pointToMove, myPoint* pointRegarding, double k)
{
    double tmpx, tmpy, tmpz;
    tmpx = pointRegarding->x + (pointToMove->x - pointRegarding->x) * k;
    tmpy = pointRegarding->y + (pointToMove->y - pointRegarding->y) * k;
    tmpz = pointRegarding->z + (pointToMove->z - pointRegarding->z) * k;
    pointToMove->x = tmpx;
    pointToMove->y = tmpy;
    pointToMove->z = tmpz;
}

void pointMove(myPoint* point, double dx, double dy, double dz)
{
    point->x += dx;
    point->y += dy;
    point->z += dz;
}
