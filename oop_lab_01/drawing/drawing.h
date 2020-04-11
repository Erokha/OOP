#ifndef OOP_LAB_01_DRAWING_H
#define OOP_LAB_01_DRAWING_H

#include "GLUT/glut.h"
#include "../frameModel/frameStructure.h"
#include <iostream>
#include "../manager/myManager.h"
#include "colorsDefine.h"
#include "../request/request.h"


myErrors draw_line(myPoint& a, myPoint& b);

myErrors modelDraw(myModel &model);

myErrors drawThrowError(int errortype);


#endif //OOP_LAB_01_DRAWING_H
