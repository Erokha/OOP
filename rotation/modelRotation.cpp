#include "modelRotation.h"
#include <stdio.h>

void rotateModelByX(myModel& model, int angle)
{
    myPoint c;
    initPoint(c, 0, 0, 0);
    for(int i = 0; i < model.num_of_points; i++)
    {
        rotatePointByX(model.masOfPoints[i], c, angle);
    }
}

void rotateModelByY(myModel& model, int angle)
{
    myPoint c;
    initPoint(c, 0, 0, 0);
    for(int i = 0; i < model.num_of_points; i++)
    {
        rotatePointByY(model.masOfPoints[i], c, angle);
    }
}

