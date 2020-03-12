#include "zoom.h"
#include <stdio.h>

void modelZoom(myModel* model, double k)
{
    printf("zooming with %lf\n",k);
    myPoint c;
    initPoint(&c, 0, 0, 0);
    for(int i = 0; i < model->num_of_points; i++)
    {
        pointZoom(&model->masOfPoints[i], &c, k);
    }
}
