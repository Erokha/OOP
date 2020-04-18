#include "zoom.h"
#include <stdio.h>

myErrors modelZoom(myMasOfPoints& points, zoomData zdat)
{
    myPoint c;
    initPoint(c, 0, 0, 0);
    if (!points.isInited)
    {
        return modelNotInited;
    }
    myErrors error = OK;
    for (int i = 0; (i < points.numOfPoints && error == OK); i++)
    {
        error = pointZoom(points.masOfPoints[i], c, zdat.zoom);
    }
    return error;
}
