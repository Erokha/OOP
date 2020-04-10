#ifndef OOP_LAB_01_DRAWING_H
#define OOP_LAB_01_DRAWING_H

#include "GLUT/glut.h"
#include "../frameModel/frameStructure.h"
#include <iostream>
#include "../manager/myManager.h"
#include "colorsDefine.h"
#include "../request/request.h"


void draw_line(myPoint& a, myPoint& b);

void modelDraw(myModel &model);

void drawThrowError(int errortype);


#endif //OOP_LAB_01_DRAWING_H
