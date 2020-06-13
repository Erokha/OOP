#ifndef OOP_LAB_01_DRAWING_H
#define OOP_LAB_01_DRAWING_H

#include <iostream>
#include "../point/point.h"
#include "colorsDefine.h"
#include "GLUT/glut.h"
#include "../request/request.h"


myErrors drawLine(projectionPoint& a, projectionPoint& b, myColor color, primitiveType type);

myErrors GLErase(colorBufferBit color);

myErrors GLShow();



#endif //OOP_LAB_01_DRAWING_H
