#include "drawing.h"


myErrors drawLine(projectionPoint& a, projectionPoint& b, myColor color, primitiveType type)
{
    glBegin(type);
    glColor3f(color.r, color.g, color.b);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glEnd();
    return OK;
}

myErrors GLShow()
{
    glutSwapBuffers();
    return OK;
}


myErrors GLErase(colorBufferBit color)
{
    glClear(color);
    return OK;
}

