#include "../point/point.h"
#include "math.h"

// Задать точке point координаты x, y
void initPoint(struct myPoint* point, double x, double y, double z)
{
    point->x = x;
    point->y = y;
    point->z = z;
}

// Изменить координату x
void setPointX(myPoint* point, double x)
{
    point->x = x;
}

// Изменить координату y
void setPointY(myPoint* point, double y)
{
    point->y = y;
}

void setPointZ(myPoint* point, double z)
{
    point->z = z;
}

void rotatePointByX(myPoint* point, double angle)
{

    double newy = point->y * cos(angle * 3.14 / 180) - point->z * sin(angle * 3.14 / 180);
    double newz = point->y * sin(angle * 3.14 / 180) + point->z * cos(angle * 3.14 / 180);
    point->y = newy;
    point->z = newz;
}

void rotatePointByY(myPoint* point, double angle)
{
    double newx = point->x * cos(angle * 3.14 / 180) + point->z * sin(angle * 3.14 / 180);
    double newz = point->z * cos(angle * 3.14 / 180) - point->x * sin(angle * 3.14 / 180);
    point->x = newx;
    point->z = newz;
}

void rotatePointByZ(myPoint* point, double angle)
{
    double newx = point->x * cos(angle * 3.14 / 180) - point->y * sin(angle * 3.14 / 180);
    double newy = point->x * sin(angle * 3.14 / 180) + point->y * cos(angle * 3.14 / 180);
    point->x = newx;
    point->y = newy;
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
