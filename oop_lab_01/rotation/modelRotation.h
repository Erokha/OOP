#ifndef OOP_LAB_01_MODELROTATION_H
#define OOP_LAB_01_MODELROTATION_H

#include "../frameModel/frameStructure.h"
#include "../point/point.h"

int modelNULLRotation(myModel* model);

int rotateModelByX(myModel* model, int angle);

int rotateModelByY(myModel* model, int angle);

int rotateModelByZ(myModel* model, int angle);

int modelPerformRotate(myModel* model);

int modelPositiveRotationX(myModel *model, double AdditiveAngle);

int modelNegativeRotationX(myModel *model, double AdditiveAngle);

int modelPositiveRotationY(myModel *model, double AdditiveAngle);

int modelNegativeRotationY(myModel *model, double AdditiveAngle);

int modelPositiveRotationZ(myModel *model, double AdditiveAngle);

int modelNegativeRotationZ(myModel *model, double AdditiveAngle);

#endif //OOP_LAB_01_MODELROTATION_H
