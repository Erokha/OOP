#ifndef OOP_LAB_01_POINT_H
#define OOP_LAB_01_POINT_H
#include <math.h>
#include <GLUT/glut.h>

struct myPoint
{
    int x;
    int y;
    int z;
};

// Задать точке point координаты x, y, z
void initPoint(myPoint* point, int x, int y, int z);

// Изменить координату x у точки point
void setPointX(myPoint* point, int x);

// Изменить координату y у точки point
void setPointY(myPoint* point, int y);

// Изменить координату z у точки point
void setPointZ(myPoint* point, int z);

void rotatePointByX(myPoint* point, int angle);

void rotatePointByY(myPoint* point, int angle);

void rotatePointByZ(myPoint* point, int angle);

void draw_line(myPoint *a, myPoint *b);
#endif //OOP_LAB_01_POINT_H
