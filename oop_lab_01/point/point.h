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

// Изменить координату x у точки point
void setPointX(myPoint* point, int x);

// Изменить координату y у точки point
void setPointY(myPoint* point, int y);

// Изменить координату z у точки point
void setPointZ(myPoint* point, int z);

void rotatePointByX(myPoint* point, double angle);

void rotatePointByY(myPoint* point, double angle);

void rotatePointByZ(myPoint* point, double angle);

void pointMove(myPoint* point, double dx, double dy, double dz);

void pointZoom(myPoint* pointToMove, myPoint* pointRegarding, double k);
#endif //OOP_LAB_01_POINT_H
