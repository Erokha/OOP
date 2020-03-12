#include "modelRotation.h"

int modelNULLRotation(myModel* model)
{
    for(int j = 0; j < model->num_of_points; j++)
    {
        initPoint(&model->rotatedPoints[j], model->masOfPoints[j].x, model->masOfPoints[j].y, model->masOfPoints[j].z);
    }
}

int rotateModelByX(myModel* model, int angle)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByX(&(model->rotatedPoints[i]), angle);
    }
    // here
}

int rotateModelByY(myModel* model, int angle)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByY(&(model->rotatedPoints[i]), angle);
    }
}

int rotateModelByZ(myModel* model, int angle)
{
    for(int i = 0; i < model->num_of_points; i++)
    {
        rotatePointByZ(&(model->rotatedPoints[i]), angle);
    }
}

int modelPerformRotate(myModel* model)
{
    modelNULLRotation(model);
    rotateModelByX(model, model->RotationAngleX);
    rotateModelByY(model, model->RotationAngleY);
    rotateModelByZ(model, model->RotationAngleZ);
}

int modelPositiveRotationX(myModel *model, double additiveAngle)
{
    model->RotationAngleX += additiveAngle;
    if (model->RotationAngleX >= 360)
    {
        model->RotationAngleX -= 360;
    } else if (model->RotationAngleX <= 360)
    {
        model->RotationAngleX += 360;
    }
}

int modelNegativeRotationX(myModel *model, double additiveAngle)
{
    model->RotationAngleX -= additiveAngle;
    if (model->RotationAngleX >= 360)
    {
        model->RotationAngleX -= 360;
    } else if (model->RotationAngleX <= 360)
    {
        model->RotationAngleX += 360;
    }
}

int modelPositiveRotationY(myModel *model, double additiveAngle)
{
    model->RotationAngleY += additiveAngle;
    if (model->RotationAngleY >= 360)
    {
        model->RotationAngleY -= 360;
    } else if (model->RotationAngleY <= 360)
    {
        model->RotationAngleY += 360;
    }
}

int modelNegativeRotationY(myModel *model, double additiveAngle)
{
    model->RotationAngleY -= additiveAngle;
    if (model->RotationAngleY >= 360)
    {
        model->RotationAngleY -= 360;
    } else if (model->RotationAngleY <= 360)
    {
        model->RotationAngleY += 360;
    }
}

int modelPositiveRotationZ(myModel *model, double additiveAngle)
{
    model->RotationAngleZ += additiveAngle;
    if (model->RotationAngleZ >= 360)
    {
        model->RotationAngleZ -= 360;
    } else if (model->RotationAngleZ <= 360)
    {
        model->RotationAngleZ += 360;
    }
}

int modelNegativeRotationZ(myModel *model, double additiveAngle)
{
    model->RotationAngleZ -= additiveAngle;
    if (model->RotationAngleZ >= 360)
    {
        model->RotationAngleZ -= 360;
    } else if (model->RotationAngleZ <= 360)
    {
        model->RotationAngleZ += 360;
    }
}