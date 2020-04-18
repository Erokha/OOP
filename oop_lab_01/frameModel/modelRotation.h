#ifndef OOP_LAB_01_MODELROTATION_H
#define OOP_LAB_01_MODELROTATION_H

#include <math.h>
#include "frameStructure.h"
#include "../request/request.h"


myErrors modelRotateByAxis(myModel& model, rotationData& rot);

myErrors modelRotateByX(myModel &m, myPoint &pointRegarding, double rotationAngle);

myErrors modelRotateByY(myModel &m, myPoint &pointRegarding, double rotationAngle);

myErrors modelRotateByZ(myModel &m, myPoint &pointRegarding, double rotationAngle);

double toRadians(double angle);

#endif //OOP_LAB_01_MODELROTATION_H
