#include "modelRotation.h"

myErrors modelRotateByX(myModel &m, myPoint &pointRegarding, double rotationAngle)
{
    if(!m.isInited)
    {
        return modelNotInited;
    }
    double alpha = toRadians(rotationAngle);
    double angleSin = sin(alpha);
    double angleCos = cos(alpha);
    myErrors error = OK;
    for (int i = 0; (i < m.points.numOfPoints && error == OK); i++) {
        error = rotatePointByX(m.points.masOfPoints[i], pointRegarding, angleCos, angleSin);
    }
    return error;
}

myErrors modelRotateByY(myModel &m, myPoint &pointRegarding, double rotationAngle)
{
    if(!m.isInited)
    {
        return modelNotInited;
    }
    double alpha = toRadians(rotationAngle);
    double angleSin = sin(alpha);
    double angleCos = cos(alpha);
    myErrors error = OK;
    for (int i = 0; (i < m.points.numOfPoints && error == OK); i++) {
        error = rotatePointByY(m.points.masOfPoints[i], pointRegarding, angleCos, angleSin);
    }
    return error;
}

myErrors modelRotateByZ(myModel &m, myPoint &pointRegarding, double rotationAngle)
{
    if(!m.isInited)
    {
        return modelNotInited;
    }
    double alpha = toRadians(rotationAngle);
    double angleSin = sin(alpha);
    double angleCos = cos(alpha);
    myErrors error = OK;
    for (int i = 0; (i < m.points.numOfPoints && error == OK); i++) {
        error = rotatePointByZ(m.points.masOfPoints[i], pointRegarding, angleCos, angleSin);
    }
    return error;
}

myErrors modelRotateByAxis(myModel& model, rotationData& rot)
{
    myErrors error = OK;
    if (!model.isInited)
    {
        return modelNotInited;
    }
    myPoint c;
    initPoint(c, 0, 0, 0);
    if (rot.rotationAxis == 'x')
    {
        error = modelRotateByX(model, c, rot.rotationAngle);
    }
    else if (rot.rotationAxis == 'y')
    {
        error = modelRotateByY(model, c, rot.rotationAngle);
    }
    else if (rot.rotationAxis == 'z')
    {
        error = modelRotateByZ(model, c, rot.rotationAngle);
    }
    else
    {
        error = NOAXIS;
    }
    return error;
}

double toRadians(double angle)
{
    return angle * M_PI / 180;
}

