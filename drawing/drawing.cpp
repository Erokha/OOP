#include "drawing.h"


void draw_line(double xs, double ys, double xf, double yf)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(xs, ys);
    glVertex2f(xf, yf);
    glEnd();
}