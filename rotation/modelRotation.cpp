#include "modelRotation.h"
#include <stdio.h>

int rotateModelByX(myModel* model, int angle)
{
    myPoint c;
    initPoint(&c, 0, 0, 0);
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByX(&(model->masOfPoints[i]), &c, angle);;
    }
}

int rotateModelByY(myModel* model, int angle)
{
    myPoint c;
    initPoint(&c, 0, 0, 0);
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByY(&(model->masOfPoints[i]), &c, angle);;
    }
}

//int rotateModelByZ(myModel* model, int angle)
//{
//    for(int i = 0; i < model->num_of_points; i++)
//    {
//        rotatePointByZ(&(model->masOfPoints[i]), angle);
//    }
//}
