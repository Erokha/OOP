#include "point.h"

// Задать точке point координаты x, y
void initPoint(myPoint* point, int x, int y, int z)
{
    point->x = x;
    point->y = y;
    point->z = z;
}

// Изменить координату x
void setPointX(myPoint* point, int x)
{
    point->x = x;
}

// Изменить координату y
void setPointY(myPoint* point, int y)
{
    point->y = y;
}

void setPointZ(myPoint* point, int z)
{
    point->z = z;
}

void rotatePointByX(myPoint* point, int angle)
{

    int newy = point->y * cos(angle * 3.14 / 180) - point->z * sin(angle * 3.14 / 180);
    int newz = point->y * sin(angle * 3.14 / 180) + point->z * cos(angle * 3.14 / 180);
    point->y = newy;
    point->z = newz;
}

void rotatePointByY(myPoint* point, int angle)
{
    int newx = point->x * cos(angle * 3.14 / 180) + point->z * sin(angle * 3.14 / 180);
    int newz = point->z * cos(angle * 3.14 / 180) - point->x * sin(angle * 3.14 / 180);
    point->x = newx;
    point->z = newz;
}

void rotatePointByZ(myPoint* point, int angle)
{
    int newx = point->x * cos(angle * 3.14 / 180) - point->y * sin(angle * 3.14 / 180);
    int newy = point->x * sin(angle * 3.14 / 180) + point->y * cos(angle * 3.14 / 180);
    point->x = newx;
    point->y = newy;
}

void draw_line(myPoint *a, myPoint *b)
{
    glBegin(GL_LINES);
    glVertex2f(a->x, a->y);
    glVertex2f(b->x, b->y);
    glEnd();
    //glFlush();
}