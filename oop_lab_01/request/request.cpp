#include "request.h"

void reqSetRotation(request& r, int rotK, char axis)
{
    r.action = modelRotation;
    r.rotationAxis = axis;
    r.rotation = rotK;
}

void reqSetZoom(request& r, double zoomK)
{
    r.action = modelScale;
    r.zoom = zoomK;
}

void reqSetMove(request& r, int dx, int dy, int dz)
{
    r.action = modelMove;
    r.dx = dx;
    r.dy = dy;
    r.dz = dz;
}
void reqSetDrawMe(request& r)
{
    r.action = drawMe;
}
void reqSetReadFromFile(request& r)
{
    r.action = modelReadFromFile;
}