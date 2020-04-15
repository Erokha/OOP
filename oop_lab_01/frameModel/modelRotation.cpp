#include "modelRotation.h"



myErrors modelRotateByAxis(myModel& model, rotationData& rot)
{
    if (model.isInited)
    {
        myPoint c;
        initPoint(c, 0, 0, 0);
        if (rot.rotationAxis == 'x')
        {
            for (int i = 0; i < model.num_of_points; i++) {
                rotatePointByX(model.masOfPointsOffset[i], c, rot.rotationAngle);
            }
            return OK;
        }
        else if (rot.rotationAxis == 'y')
        {
            for (int i = 0; i < model.num_of_points; i++) {
                rotatePointByY(model.masOfPointsOffset[i], c, rot.rotationAngle);
            }
            return OK;
        }
        else
        {
            return NOAXIS;
        }
    }
    else
    {
        return modelNotInited;
    }
}


