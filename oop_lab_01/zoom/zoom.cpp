#include "zoom.h"
#include <stdio.h>

void modelZoom(myModel* model, double k)
{
    printf("zooming with %lf\n",k);
    for (int i = 0; i < model->num_of_points; i++)
    {
        pointZoom(&model->rotatedPoints[i], &model->center, k);
    }
}
