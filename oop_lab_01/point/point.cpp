#include "../point/point.h"
#include "math.h"

myErrors initPoint(struct myPoint& point, double x, double y, double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
    point.isInited = true;
    return OK;
}

myErrors rotatePointByX(myPoint& pointToRotate, myPoint& pointRegarding, double alpha)
{
    if (pointToRotate.isInited && pointRegarding.isInited)
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
        return OK;
    }
    else
    {
        return POINTNOTINITED;
    }
}

myErrors rotatePointByY(myPoint& pointToRotate, myPoint& pointRegarding, double alpha)
{
    if (pointToRotate.isInited && pointRegarding.isInited)
    {
        double newx, newy, newz;
        double angle = alpha * 3.14 / 180;
        double co = cos(angle);
        double si = sin(angle);
        newx = pointRegarding.x + (pointToRotate.x - pointRegarding.x) * co + (pointToRotate.z - pointRegarding.z) * si;
        newy = pointToRotate.y;
        newz = pointRegarding.z + (pointRegarding.x - pointToRotate.x) * si + (pointToRotate.z - pointRegarding.z) * co;
        pointToRotate.x = newx;
        pointToRotate.y = newy;
        pointToRotate.z = newz;
    }
    else
    {
        return POINTNOTINITED;
    }
}


myErrors pointZoom(myPoint& pointToMove, myPoint& pointRegarding, double k)
{
    if (pointToMove.isInited)
    {
        double tmpx, tmpy, tmpz;
        tmpx = pointRegarding.x + (pointToMove.x - pointRegarding.x) * k;
        tmpy = pointRegarding.y + (pointToMove.y - pointRegarding.y) * k;
        tmpz = pointRegarding.z + (pointToMove.z - pointRegarding.z) * k;
        pointToMove.x = tmpx;
        pointToMove.y = tmpy;
        pointToMove.z = tmpz;
        return OK;
    } else{
        return POINTNOTINITED;
    }
}

myErrors pointMove(myPoint& point, double dx, double dy, double dz) {
    if (point.isInited)
    {
        point.x += dx;
        point.y += dy;
        point.z += dz;
        return OK;
    }
    else
    {
        return POINTNOTINITED;
    }
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

myErrors pointCoordinateAddition(myPoint& result, myPoint& a, myPoint& b)
{
    if (a.isInited && b.isInited)
    {
        result.x = a.x + b.x;
        result.y = a.y + b.y;
        result.z = a.y + b.y;
        result.isInited = true;
        return OK;
    }
    else
    {
        return POINTNOTINITED;
    }
}