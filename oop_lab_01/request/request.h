#ifndef OOP_LAB_01_REQUEST_H
#define OOP_LAB_01_REQUEST_H
#include "../defines.h"

struct request
{
    myAction action;
    int dx;
    int dy;
    int dz;
    char rotationAxis;
    int rotation;
    double zoom;
};

void reqSetRotation(request& r, int rotK, char axis);

void reqSetZoom(request& r, double zoomK);

void reqSetMove(request& r, int dx, int dy, int dz);

void reqSetDrawMe(request& r);

void reqSetReadFromFile(request& r);

#endif //OOP_LAB_01_REQUEST_H
