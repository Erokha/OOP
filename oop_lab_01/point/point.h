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

struct myMasOfPoints
{
    int numOfPoints;
    myPoint* masOfPoints;
    bool isInited;
};


myErrors initPoint(myPoint& point, double x, double y, double z);

myErrors rotatePointByX(myPoint& pointToRotate, myPoint& pointRegarding, double cos, double sin);

myErrors rotatePointByY(myPoint& pointToRotate, myPoint& pointRegarding, double cos, double sin);

myErrors rotatePointByZ(myPoint& pointToRotate, myPoint& pointRegarding, double cos, double sin);

myErrors pointMove(myPoint& point, double dx, double dy, double dz);

myErrors pointZoom(myPoint& pointToMove, myPoint& pointRegarding, double k);

double getPointX(myPoint& point);

double getPointY(myPoint& point);

double getPointZ(myPoint& point);

myErrors pointCoordinateAddition(myPoint& result, myPoint& additivePoint);

myErrors readPointFromFile(myPoint& a, FILE* f);

myErrors allocateMasOfPoints(myMasOfPoints& mas, int n);

myErrors masOfPointsCheck(myMasOfPoints& mas);

myErrors masOfPointsBasicInit(myMasOfPoints& mas);

myErrors masOfPointsFreeMemory(myMasOfPoints& mas);

myErrors pointTransfer(myPoint& dest, myPoint& source);

myErrors masOfPointsTransfer(myMasOfPoints& dest, myMasOfPoints& source);

int getNumOfPoints(myMasOfPoints& mas);

bool masOfPointsShowInitialization(myMasOfPoints& mas);

bool pointShowInitialization(myPoint& point);



#endif //OOP_LAB_01_POINT_H
