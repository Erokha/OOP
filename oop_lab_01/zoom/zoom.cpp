#include "zoom.h"
#include <stdio.h>

myErrors modelZoom(myModel& model, zoomData zdat)
{
    myPoint c;
    initPoint(c, 0, 0, 0);
    if (model.isInited)
    {
        for (int i = 0; i < model.num_of_points; i++)
        {
            if (pointZoom(model.masOfPointsOffset[i], c, zdat.zoom) != OK)
            {
                return ZOOMERROR;
            }
        }
        return OK;
    } else
    {
        return modelNotInited;
    }
}
