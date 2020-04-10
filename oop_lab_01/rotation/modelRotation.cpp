#include "modelRotation.h"
#include <stdio.h>



int rotateModelbyAxis(myModel& model, int angle, char axis)
{
    if (model.isInited)
    {
        myPoint c;
        initPoint(c, 0, 0, 0);
        if (axis == 'x')
        {
            for (int i = 0; i < model.num_of_points; i++) {
                rotatePointByX(model.masOfPointsOffset[i], c, angle);
            }
        }
        else
        {
            for (int i = 0; i < model.num_of_points; i++) {
                rotatePointByY(model.masOfPointsOffset[i], c, angle);
            }
        }
    }
    else
    {
        return modelNotInited;
    }
}

int rotateModelByY(myModel& model, int angle)
{
    if (model.isInited)
    {
        myPoint c;
        initPoint(c, 0, 0, 0);
        for (int i = 0; i < model.num_of_points; i++) {
            rotatePointByY(model.masOfPointsOffset[i], c, angle);
        }
    }
    else
    {
        return modelNotInited;
    }
}

