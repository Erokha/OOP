#ifndef OOP_LAB_01_POINT_H
#define OOP_LAB_01_POINT_H

struct myPoint
{
    double x;
    double y;
    double z;
};

// Задать точке point координаты x, y, z
void initPoint(myPoint* point, double x, double y, double z);

void copyPoint(myPoint* source, myPoint* dest);

void rotatePointByX(myPoint* pointToRotate, myPoint* pointRegarding, double alpha);

void rotatePointByY(myPoint* pointToRotate, myPoint* pointRegarding, double alpha);

void rotatePointByZ(myPoint* point, double angle);

void pointMove(myPoint* point, double dx, double dy, double dz);

void pointZoom(myPoint* pointToMove, myPoint* pointRegarding, double k);

#endif //OOP_LAB_01_POINT_H
