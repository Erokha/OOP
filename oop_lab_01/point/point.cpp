#include "../point/point.h"
#include "math.h"

void initPoint(struct myPoint& point, double x, double y, double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

void rotatePointByX(myPoint& pointToRotate, myPoint& pointRegarding, double alpha)
{
    double angle = alpha * 3.14 / 180;
    double newx, newy, newz;
    double co = cos(angle);
    double si = sin(angle);
    newx = pointToRotate.x;
    newy = pointRegarding.y + (pointToRotate.y - pointRegarding.y) * co + (pointRegarding.z - pointToRotate.z) * si;
    newz = pointRegarding.z + (pointToRotate.y - pointRegarding.y) * si + (pointToRotate.z - pointRegarding.z) * co;
    pointToRotate.x = newx;
    pointToRotate.y = newy;
    pointToRotate.z = newz;
}

void rotatePointByY(myPoint& pointToRotate, myPoint& pointRegarding, double alpha)
{
    double newx, newy, newz;
    double angle = alpha * 3.14 / 180;
    double co = cos(angle);
    double si = sin(angle);
    newx = pointRegarding.x+(pointToRotate.x-pointRegarding.x)*co+(pointToRotate.z-pointRegarding.z)*si;
    newy = pointToRotate.y;
    newz = pointRegarding.z+(pointRegarding.x-pointToRotate.x)*si+(pointToRotate.z-pointRegarding.z)*co;
    pointToRotate.x = newx;
    pointToRotate.y = newy;
    pointToRotate.z = newz;
}


void pointZoom(myPoint& pointToMove, myPoint& pointRegarding, double k)
{
    double tmpx, tmpy, tmpz;
    tmpx = pointRegarding.x + (pointToMove.x - pointRegarding.x) * k;
    tmpy = pointRegarding.y + (pointToMove.y - pointRegarding.y) * k;
    tmpz = pointRegarding.z + (pointToMove.z - pointRegarding.z) * k;
    pointToMove.x = tmpx;
    pointToMove.y = tmpy;
    pointToMove.z = tmpz;
}

void pointMove(myPoint& point, double dx, double dy, double dz)
{
    point.x += dx;
    point.y += dy;
    point.z += dz;
}

double getPointX(myPoint& point)
{
    return point.x;
}

double getPointY(myPoint& point)
{
    return point.y;
}

double getPointZ(myPoint& point)
{
    return point.z;
}

void pointCoordinateAddition(myPoint& a, myPoint& b, myPoint& result)
{
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.y + b.y;
}