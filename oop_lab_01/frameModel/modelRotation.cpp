#include "modelRotation.h"

myErrors modelRotateByX(myMasOfPoints& points, double rotationAngle)
{
    if(!points.isInited)
    {
        return modelNotInited;
    }
    double alpha = toRadians(rotationAngle);
    double angleSin = sin(alpha);
    double angleCos = cos(alpha);
    myErrors error = OK;
    for (int i = 0; (i < points.numOfPoints && error == OK); i++) {
        error = rotatePointByX(points.masOfPoints[i], angleCos, angleSin);
    }
    return error;
}

myErrors modelRotateByY(myMasOfPoints& points, double rotationAngle)
{
    if(!points.isInited)
    {
        return modelNotInited;
    }
    double alpha = toRadians(rotationAngle);
    double angleSin = sin(alpha);
    double angleCos = cos(alpha);
    myErrors error = OK;
    for (int i = 0; (i < points.numOfPoints && error == OK); i++) {
        error = rotatePointByY(points.masOfPoints[i], angleCos, angleSin);
    }
    return error;
}

myErrors modelRotateByZ(myMasOfPoints& points, double rotationAngle)
{
    if(!points.isInited)
    {
        return modelNotInited;
    }
    double alpha = toRadians(rotationAngle);
    double angleSin = sin(alpha);
    double angleCos = cos(alpha);
    myErrors error = OK;
    for (int i = 0; (i < points.numOfPoints && error == OK); i++) {
        error = rotatePointByZ(points.masOfPoints[i], angleCos, angleSin);
    }
    return error;
}

myErrors modelRotateByAxis(myModel& model, rotationData& rot)
{
    if (!model.isInited)
    {
        return modelNotInited;
    }
    myErrors error = OK;
    if (rot.rotationAxis == 'x')
    {
        error = modelRotateByX(model.points, rot.rotationAngle);
    }
    else if (rot.rotationAxis == 'y')
    {
        error = modelRotateByY(model.points, rot.rotationAngle);
    }
    else if (rot.rotationAxis == 'z')
    {
        error = modelRotateByZ(model.points, rot.rotationAngle);
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

