#ifndef OOP_LAB_01_POINT_H
#define OOP_LAB_01_POINT_H

#include "../defines.h"
struct myPoint
{
    double x;
    double y;
    double z;
    bool isInited;
};


myErrors initPoint(myPoint& point, double x, double y, double z);

myErrors  rotatePointByX(myPoint& pointToRotate, myPoint& pointRegarding, double alpha);

myErrors rotatePointByY(myPoint& pointToRotate, myPoint& pointRegarding, double alpha);

myErrors pointMove(myPoint& point, double dx, double dy, double dz);

myErrors pointZoom(myPoint& pointToMove, myPoint& pointRegarding, double k);

double getPointX(myPoint& point);

double getPointY(myPoint& point);

double getPointZ(myPoint& point);

myErrors pointCoordinateAddition(myPoint& a, myPoint& b, myPoint& result);


#endif //OOP_LAB_01_POINT_H
