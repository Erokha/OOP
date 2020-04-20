#ifndef OOP_LAB_01_MODELROTATION_H
#define OOP_LAB_01_MODELROTATION_H

#include <math.h>
#include "frameStructure.h"
#include "../request/request.h"


myErrors modelRotateByAxis(myModel& model, rotationData& rot);

myErrors modelRotateByX(myMasOfPoints& points, double rotationAngle);

myErrors modelRotateByY(myMasOfPoints& points, double rotationAngle);

myErrors modelRotateByZ(myMasOfPoints& points, double rotationAngle);

double toRadians(double angle);

#endif //OOP_LAB_01_MODELROTATION_H
