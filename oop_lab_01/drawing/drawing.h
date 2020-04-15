#ifndef OOP_LAB_01_DRAWING_H
#define OOP_LAB_01_DRAWING_H

#include <iostream>
#include "../glutWindow/myGLUT.h"
#include "../frameModel/frameStructure.h"
#include "colorsDefine.h"


myErrors draw_line(myPoint& a, myPoint& b);

myErrors modelDraw(myModel &model);

myErrors drawThrowError(int errortype);


#endif //OOP_LAB_01_DRAWING_H
