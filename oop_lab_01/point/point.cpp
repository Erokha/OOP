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

myErrors rotatePointByX(myPoint& pointToRotate, myPoint& pointRegarding, double cos, double sin)
{
    if (!pointToRotate.isInited || !pointRegarding.isInited)
    {
        return POINTNOTINITED;
    }
    double newy, newz;
    newy = pointRegarding.y + (pointToRotate.y - pointRegarding.y) * cos - (pointToRotate.z - pointRegarding.z) * sin;
    newz = pointRegarding.z + (pointToRotate.y - pointRegarding.y) * sin + (pointToRotate.z - pointRegarding.z) * cos;
    pointToRotate.y = newy;
    pointToRotate.z = newz;
    return OK;
}

myErrors rotatePointByY(myPoint& pointToRotate, myPoint& pointRegarding, double cos, double sin)
{
    if (!pointToRotate.isInited || !pointRegarding.isInited)
    {
        return POINTNOTINITED;
    }
    double newx, newz;
    newx = pointRegarding.x + (pointToRotate.x - pointRegarding.x) * cos + (pointToRotate.z - pointRegarding.z) * sin;
    newz = pointRegarding.z - (pointToRotate.x - pointRegarding.x) * sin + (pointToRotate.z - pointRegarding.z) * cos;
    pointToRotate.x = newx;
    pointToRotate.z = newz;
    return OK;
}

myErrors rotatePointByZ(myPoint& pointToRotate, myPoint& pointRegarding, double cos, double sin)
{
    if (!pointToRotate.isInited || !pointRegarding.isInited)
    {
        return POINTNOTINITED;
    }
    double newx, newy;
    newx = pointRegarding.x + (pointToRotate.x - pointRegarding.x) * cos - (pointToRotate.y - pointRegarding.y) * sin;
    newy = pointRegarding.y + (pointToRotate.x - pointRegarding.x) * sin + (pointToRotate.y - pointRegarding.y) * cos;
    pointToRotate.x = newx;
    pointToRotate.y = newy;
    return OK;
}


myErrors pointZoom(myPoint& pointToMove, myPoint& pointRegarding, double k)
{
    if (!pointToMove.isInited || !pointRegarding.isInited)
    {
        return POINTNOTINITED;
    }
    pointToMove.x = pointRegarding.x + (pointToMove.x - pointRegarding.x) * k;
    pointToMove.y = pointRegarding.y + (pointToMove.y - pointRegarding.y) * k;
    pointToMove.z = pointRegarding.z + (pointToMove.z - pointRegarding.z) * k;
    return OK;
}

myErrors pointMove(myPoint& point, double dx, double dy, double dz) {
    if (!point.isInited)
    {
        return POINTNOTINITED;
    }
    point.x += dx;
    point.y += dy;
    point.z += dz;
    return OK;
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

myErrors pointCoordinateAddition(myPoint& result, myPoint& additivePoint)
{
    if (!result.isInited || !additivePoint.isInited)
    {
        return POINTNOTINITED;
    }
    result.x += additivePoint.x;
    result.y += additivePoint.y;
    result.z += additivePoint.z;
    return OK;
}

myErrors pointTransfer(myPoint& dest, myPoint& source)
{
    dest.x = source.x;
    dest.y = source.y;
    dest.z = source.z;
    dest.isInited = source.isInited;
    return OK;
}

myErrors readPointFromFile(myPoint& a, FILE* f)
{
    if (f == NULL)
    {
        return NOFILE;
    }
    double x, y, z;
    if (fscanf(f, "%lf %lf %lf", &x, &y, &z) != 3)
    {
        return POINTSERROR;
    }
    return initPoint(a, x, y, z);
}

myErrors allocateMasOfPoints(myMasOfPoints& mas, int n)
{
    if (n <= 0)
    {
        return EMPTYMAS;
    }
    mas.numOfPoints = n;
    mas.masOfPoints = new myPoint[mas.numOfPoints];
    if (mas.masOfPoints == NULL)
    {
        return NOFREESPACE;
    }
    return OK;
}

myErrors masOfPointsCheck(myMasOfPoints& mas)
{
    if (mas.numOfPoints <= 0)
    {
        return EMPTYMAS;
    }
    int count = 0;
    for (int i = 0; i < mas.numOfPoints; i++)
    {
        if (mas.masOfPoints[i].isInited)
        {
            count++;
        }
    }
    if (count == mas.numOfPoints)
    {
        mas.isInited = true;
        return OK;
    } else
    {
        return POINTNOTINITED;
    }
}

myErrors masOfPointsBasicInit(myMasOfPoints& mas)
{
    mas.isInited = false;
    mas.numOfPoints = 0;
    mas.masOfPoints = NULL;
    return OK;
}

myErrors masOfPointsFreeMemory(myMasOfPoints& mas)
{
    delete mas.masOfPoints;
    mas.numOfPoints = 0;
    mas.isInited = false;
    return OK;
}

myErrors masOfPointsTransfer(myMasOfPoints& dest, myMasOfPoints& source)
{
    myErrors error;
    dest.numOfPoints = source.numOfPoints;
    error = allocateMasOfPoints(dest, dest.numOfPoints);
    if (error != OK)
    {
        return error;
    }
    error = OK;
    for(int i = 0; (i < dest.numOfPoints && error == OK); i++)
    {
        error = pointTransfer(dest.masOfPoints[i], source.masOfPoints[i]);
    }
    if (error == OK)
    {
        dest.isInited = source.isInited;
    }
    return error;
}

int getNumOfPoints(myMasOfPoints& mas)
{
    return mas.numOfPoints;
}

bool masOfPointsShowInitialization(myMasOfPoints& mas)
{
    return mas.isInited;
}

bool pointShowInitialization(myPoint& point)
{
    return point.isInited;
}