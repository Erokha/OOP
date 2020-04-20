#include "zoom.h"
#include <stdio.h>

myErrors modelZoom(myMasOfPoints& points, zoomData zdat)
{
    if (!points.isInited)
    {
        return modelNotInited;
    }
    myErrors error = OK;
    for (int i = 0; (i < points.numOfPoints && error == OK); i++)
    {
        error = pointZoom(points.masOfPoints[i], zdat.zoom);
    }
    return error;
}
