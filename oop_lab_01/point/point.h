#ifndef OOP_LAB_01_POINT_H
#define OOP_LAB_01_POINT_H

struct myPoint
{
    double x;
    double y;
    double z;
};


void initPoint(myPoint& point, double x, double y, double z);

void rotatePointByX(myPoint& pointToRotate, myPoint& pointRegarding, double alpha);

void rotatePointByY(myPoint& pointToRotate, myPoint& pointRegarding, double alpha);

void pointMove(myPoint& point, double dx, double dy, double dz);

void pointZoom(myPoint& pointToMove, myPoint& pointRegarding, double k);

double getPointX(myPoint& point);

double getPointY(myPoint& point);

double getPointZ(myPoint& point);

void pointCoordinateAddition(myPoint& a, myPoint& b, myPoint& result);

#endif //OOP_LAB_01_POINT_H
